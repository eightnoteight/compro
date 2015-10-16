#include <bits/stdc++.h>
using namespace std;
template <class number>
void input(number *ptr){
    register char c = getchar_unlocked();
    bool sign = false;
    while (c < 33)
        c = getchar_unlocked();
    *ptr = 0;
    if (c == '-'){
        sign = true;
        c = getchar_unlocked();
    }
    while (c > 33){
        *ptr = (*ptr * 10) + (c - '0');
        c = getchar_unlocked();
    }
    if (sign)
        *ptr *= -1;

}
void print(const char* format, ...){
    va_list arguments;
    va_start(arguments, format);
    register char c;
    char num[20];
    int i = 0, j;
    long n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
            i += 2;
            n = va_arg(arguments, long);
            j = 0;
            do{
                num[j++] = n%10 + 48;
                n /= 10;
            }  while (n != 0);
            j--;
            while (j >= 0)
                putchar_unlocked(num[j--]);
        }
    }
    va_end(arguments);
}


class maxelem
{
public:
	int32_t* arr;
	vector<int32_t> tree;
	int32_t size;
	int32_t upidx;
	int32_t upval;
	int32_t qulo;
	int32_t quhi;
	maxelem(int32_t* array, int32_t n) {
		arr = array;
		tree.resize((2*(1 << (int32_t)ceil(log2(n)))) + 1);
		construct(0, n, 0);
		size = n;
	}
	void construct(int32_t lo, int32_t hi, int32_t idx) {
		if (hi - lo == 1) {
			tree[idx] = lo;
			return;
		}
		int32_t mid = lo + ((hi - lo) / 2);
		construct(lo, mid, 2*idx + 1);
		construct(mid, hi, 2*idx + 2);
		tree[idx] = ((arr[tree[2*idx + 1]] > arr[tree[2*idx + 2]]) ? (tree[2*idx + 1]) : (tree[2*idx + 2]));
	}
	void update_util(int32_t lo, int32_t hi, int32_t idx) {
		if (hi - lo == 1) {
			if (lo == upidx) {
				arr[upidx] = upval;
				tree[idx] = upidx;
			}
			return;
		}
		int32_t mid = lo + ((hi - lo) / 2);
		if (upidx < mid)
			update_util(lo, mid, 2*idx + 1);
		else
			update_util(mid, hi, 2*idx + 2);
		tree[idx] = arr[tree[2*idx + 1]] > arr[tree[2*idx + 2]]? tree[2*idx + 1] : tree[2*idx + 2];
	}
	void update(int32_t idx, int32_t nval) {
		upidx = idx;
		upval = nval;
		update_util(0, size, 0);
	}
	int32_t find_util(int32_t lo, int32_t hi, int32_t idx) {
		if (quhi <= lo or qulo >= hi or lo >= hi) {
			return -1;
		}
		if (qulo <= lo and hi <= quhi) {
			return tree[idx];
		}
		int32_t mid = lo + ((hi - lo) / 2);
		int32_t left = find_util(lo, mid, 2*idx + 1);
		int32_t right = find_util(mid, hi, 2*idx + 2);
		if (left == -1)
			return right;
		if (right == -1)
			return left;
		return ((arr[left] > arr[right]) ? (left): (right));
	}
	int32_t find(int32_t qlo, int32_t qhi) {
		qulo = qlo;
		quhi = qhi;
		return find_util(0, size, 0);
	}
};
int main(int argc, char const *argv[])
{
	int32_t n;
	input(&n);
	int32_t arr[n + 1];
	for (int i = 0; i < n; ++i)
	{
		input(&arr[i]);
	}
	arr[n] = 0;
	int32_t q;
	maxelem segt(arr, n);
	input(&q);
	while(q--) {
		char ty;
		int32_t x;
		int32_t y;
		input(&ty);
		input(&x);
		input(&y);
		x--;
		if (ty == 33) /* Query Operation */
		{
			int32_t result;
			if(y - x == 2)
			{
				result = arr[x] + arr[x + 1];
			}
			else
			{
				int32_t tmp1 = segt.find(x, y);
				// cout << "x = " << x << "; y = " << y << "; tmp1 = " << tmp1 << endl;
				result = arr[tmp1];
				int32_t mtmp1 = 0, mtmp2 = 0;
				if (tmp1 > x)
					mtmp1 = arr[segt.find(x, tmp1)];
				if (tmp1 < y - 1)
					mtmp2 = arr[segt.find(tmp1 + 1, y)];
				result += max(mtmp2, mtmp1);
			}
			print("{}\n", result);
		}
		else
			segt.update(x, y);
	}

    return 0;
}
