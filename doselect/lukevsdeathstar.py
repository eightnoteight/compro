import requests
import sys
from itertools import count
from datetime import datetime
import json

def resolveJsonData(data, query_date):
    issues_urls = []
    invalid_t = 0
    for isue in data:
        created_at = datetime.strptime(isue['created_at'], "%Y-%m-%dT%H:%M:%SZ")
        if created_at > query_date:
            invalid_t += 1
        x, y = created_at, query_date
        if x.day == y.day and x.month == y.month and x.year == y.year:
            issues_urls.append(isue['html_url'])
    if invalid_t == len(data) and not issues_urls:
        return None
    return issues_urls

def getIssuesAndPulls(issues_url, since_str, date, dheaders, org, rep):
    issues = []
    with requests.Session() as ses:
        for x in count(1):
            resp = ses.get(issues_url, params={
                'q': 'repo:{org}/{rep} created:{yyyy:0>4}-{mm:0>2}-{dd:0>2}'.format(
                    org=org, rep=rep, yyyy=date.year, mm=date.month, dd=date.day),
                'page': str(x),
                'sort': 'created',
                'order': 'asc',
            }, headers=dheaders)
            if resp.status_code == 200:
                data = resp.json()['items']
                if not data:
                    break
                cissues = resolveJsonData(data, date)
                if cissues is None:
                    break
                issues.extend(cissues)
            else:
                print('error: resp.status_code={}; resp.content={}'.format(
                    resp.status_code, resp.content), file=sys.stderr)
                break
    return issues

def main():
    org, rep, ddmmyy = input().split()
    dd, mm, yyyy = ddmmyy.split('-')
    dheaders = {
        'accept': 'application/vnd.github.v3+json',
        'authorization': 'token 032b7c134a05500f56e85a44a5d95ef9984737d1',
        # don't worry i will revoke it, just to avoid 403's
    }
    issues_url = 'https://api.github.com/search/issues'
    since_str = '{yyyy:0>4}-{mm:0>2}-{dd:0>2}T00:00:00Z'.format(yyyy=yyyy, mm=mm, dd=dd)
    date = datetime.strptime(since_str, "%Y-%m-%dT%H:%M:%SZ")
    issues = getIssuesAndPulls(issues_url, since_str, date, dheaders, org, rep)
    print('\n'.join(issues))

if __name__ == '__main__':
    main()
