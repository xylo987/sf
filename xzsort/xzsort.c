#include <stdio.h>

/*
 * 没运行过，不知道对不对
 */
int main() {
	void xzsort(int [], int);
	void xzsort_desc(int [], int);
	const int size = 1000;
	int L[size] = {};
	int i = 0;
	int j = size;
    int last = size - 1;
	while (i < size){
		L[i] = j --;
		i ++;
	}
	xzsort_desc(L,size);
	//xzsort(L,size);
	for(i = 0; i < size; i++){
        if (i == last) 
            printf("%d\n",L[i]);
        else
            printf("%d,",L[i]);
	}
	return 0;
}

/*
 * 升序
 */
void xzsort(int L[], int size) {
	int n, m, tmp, mid_id;

	m = 0;
	mid_id = -1;
	while (m < size) {
		n = m + 1;
		while (n < size) {
			if (L[n] < L[m]) {
				mid_id = n;
			}
			n ++;
		}
		if (mid_id != -1) {
			tmp = L[m];
			L[m] = L[mid_id];
			L[mid_id] = tmp;
            mid_id = -1;
		}
		m ++;
	}
}

/*
 * 降序
 */
void xzsort_desc(int L[], int size) {
	int n, m, tmp, mid_id;

	m = 0;
	mid_id = -1;
	while (m < size) {
		n = m + 1;
		while (n < size) {
			if (L[n] > L[m]) {
				mid_id = n;
			}
			n ++;
		}
		if (mid_id != -1) {
			tmp = L[m];
			L[m] = L[mid_id];
			L[mid_id] = tmp;
		}
		m ++;
	}
}
