/*
 * 57.cpp
 *
 *  Created on: 2019/08/05
 *      Author: hhhhh
 */


void swap(int *m, int *n){
	int tmp = *m;
	*m = *n;
	*n = tmp;
}

int partition (int array[], int left, int right) {
  int i, j, pivot;
  i = left;
  j = right + 1;
  pivot = left;   // 先頭要素をpivotとする

  do {
    do { i++; } while (array[i] < array[pivot]);
    do { j--; } while (array[pivot] < array[j]);
    if (i < j) { swap(&array[i], &array[j]); }
  } while (i < j);

  swap(&array[pivot], &array[j]);   //pivotを更新

  return j;
}

/* クイックソート */
void quick_sort (int array[], int left, int right) {
  int pivot;

  if (left < right) {
    pivot = partition(array, left, right);
    quick_sort(array, left, pivot-1);
    quick_sort(array, pivot+1, right);
  }
}
