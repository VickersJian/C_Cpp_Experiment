#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;

typedef int keyType;
typedef int infoType;
struct RecordType {
	keyType key;
	infoType info;
};
struct SortArr {
	int cnt;
	RecordType* record;
};
void swap(SortArr* arr,int i,int j) {
	RecordType temp = arr->record[i];
	arr->record[i] = arr->record[j];
	arr->record[j] = temp;
}
void insertSort(SortArr* arr) {
	RecordType temp;
	int i, j;
	int low, mid, high;
	for (i = 1; i < arr->cnt; i++) {
		
		temp = arr->record[i];

		//Ö±½Ó
		//j = i - 1;
		//while (temp.key < arr->record[j].key&&j >= 0) {
		//	arr->record[j + 1] = arr->record[j];
		//	j--;
		//}
		//if (j + 1 != i) {
		//	arr->record[j + 1] = temp;
		//}

		//¶þ·Ö
		//low = 0;
		//high = i - 1;
		//while (low <= high) {
		//	mid = (low + high) / 2;
		//	if (arr->record[mid].key > temp.key) {
		//		high = mid - 1;
		//	}
		//	else {
		//		low = mid + 1;
		//	}
		//}
		//if (low != i) {
		//	for (j = i - 1; j >= low; j--) {
		//		arr->record[j + 1] = arr->record[j];
		//	}
		//	arr->record[j+1] = temp;
		//}

	}
	
}

void insertSort(SortArr* arr,int d) {
	RecordType temp;
	int i, j, increment;
	for (increment = d; increment > 0; increment /= 2) {
		//for (int k = increment; k < 2 * increment; k++) {
		//	for (i = k; i < arr->cnt; i += increment) {
		//		temp = arr->record[i];
		//		j = i - increment;
		//		while (arr->record[j].key > temp.key&&j >= 0) {
		//			arr->record[j + increment] = arr->record[j];
		//			j -= increment;
		//		}
		//		if (j + increment != i) {
		//			arr->record[j + increment] = temp;
		//		}
		//	}
		//}
		for (i = increment; i < arr->cnt; i++) {
			j = i - increment;
			temp = arr->record[i];
			while (arr->record[j].key > temp.key&&j >= 0) {
				arr->record[j + increment] = arr->record[j];
				j -= increment;
			}
			if (j + increment != i) {
				arr->record[j + increment] = temp;
			}
		}
	}
}

void quickSort(SortArr* arr, int l, int r) {
	int i, j;
	RecordType temp;
	if (l >= r) 
		return;
	i = l;
	j = r;
	temp = arr->record[i];
	while (i != j) {
		while (arr->record[j].key < temp.key&&i < j)
			j--;
		if (i < j)
			arr->record[i++] = arr->record[j];
		while (arr->record[i].key > temp.key&&i < j)
			i++;
		if (i < j)
			arr->record[j--] = arr->record[i];
	}
	arr->record[i] = temp;
	quickSort(arr, l, i - 1);
	quickSort(arr, i + 1, r);
}

int main() {
	int x = 10;
	SortArr arr;
	arr.cnt = x;
	arr.record = (RecordType*)malloc(x * sizeof(RecordType));
	for (int i = 0; i < x; i++) {
		arr.record[i].key = rand() % 100 + 1;
		cout << arr.record[i].key << " ";
	}
	cout << endl;
	quickSort(&arr,0,9);


	//insertSort(arr, 5000);//Ö±½Ó²åÈëÅÅÐò(ÉýÐò)40.242Çë°´
	//insertSort2(arr, 5000);//Ö±½Ó²åÈëÅÅÐò£¨½µÐò£©
	//bubbleSort(arr, 5000);//Ã°ÅÝÅÅÐò(ÉýÐò)
	//bubbleSort2(arr, 5000);//Ã°ÅÝÅÅÐò£¨½µÐò£©
	//RadixSort(arr, 5000);//»ùÊýÅÅÐò(ÉýÐò)
	//RadixSort2(arr,5000);//»ùÊýÅÅÐò£¨½µÐò£©
	//mergesort(arr, 0, 4999, r);//¹é²¢ÅÅÐò(ÉýÐò)
	//mergesort2(arr, 0, 4999,r);//¹é²¢ÅÅÐò£¨½µÐò£©

	
	for (int i = 0; i < x; i++) {
		cout << arr.record[i].key << " ";
	}

	system("pause");
	return 0;
}