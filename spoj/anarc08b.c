#include <stdio.h>
#include <string.h>

int display(char x, char y, char z)
{
    switch(x)
    {
        case '0':
            switch(y)
            {
                case '1':
                    if(z == '0')
                        return 1;
                    else
                        return 7;
                case '6':
                    return 0;
                case '7':
                    return 3;
                case '9':
                    return 2;
            }
        case '1':
            switch(z)
            {
                case '3':
                    return 5;
                case '6':
                    return 4;
                case '7':
                    if(y == '2')
                        return 8;
                    else
                        return 9;
                case '9':
                    return 6;
            }
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    char expr[100]; // 2 * 9 * 3
    char ans[100];
    char* back[] = {
        "360",
        "010",
        "390",
        "970",
        "601",
        "301",
        "911",
        "110",
        "721",
        "701"
    };
    long long int x, val, tmp, length, i;
    char chrtmp;

    while(1){
        scanf("%s", expr);
        if(!strcmp(expr, "BYE"))
            break;
        x = 0;
        val = 0;
        tmp = 0;
        while(expr[x] != '\0')
        {
            if(expr[x] == '+' || expr[x] == '=')
            {
                val += tmp;
                tmp = 0;
                x++;
            } 
            else 
            {
                tmp = (tmp * 10) + display(expr[x], expr[x + 1], expr[x + 2]);
                x += 3;
            }
        }
        x = 0;
        ans[0] = '\0';
        while(val)
        {
            strcat(ans, back[val % 10]);
            val /= 10;
        }
        length = strlen(ans);
        for(i=0; i<length/2; i++)
        {
            chrtmp = ans[i];
            ans[i] = ans[length - i - 1];
            ans[length - i - 1] = chrtmp; 
        }
        printf("%s%s\n", expr, ans);
    }
    return 0;
}

