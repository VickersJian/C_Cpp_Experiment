////堆排序
///**
//	 * 建堆
//	 *
//	 * @param arrays          看作是完全二叉树
//	 * @param currentRootNode 当前父节点位置
//	 * @param size            节点总数
//	 */
//void heapify(int arrays[], int currentRootNode, int size) {
//
//	if (currentRootNode < size) {
//		//左子树和右字数的位置
//		int left = 2 * currentRootNode + 1;
//		int right = 2 * currentRootNode + 2;
//
//		//把当前父节点位置看成是最大的
//		int max = currentRootNode;
//
//		if (left < size) {
//			//如果比当前根元素要大，记录它的位置
//			if (arrays[max] < arrays[left]) {
//				max = left;
//			}
//		}
//		if (right < size) {
//			//如果比当前根元素要大，记录它的位置
//			if (arrays[max] < arrays[right]) {
//				max = right;
//			}
//		}
//		//如果最大的不是根元素位置，那么就交换
//		if (max != currentRootNode) {
//			int temp = arrays[max];
//			arrays[max] = arrays[currentRootNode];
//			arrays[currentRootNode] = temp;
//
//			继续比较，直到完成一次建堆
//			heapify(arrays, max, size);
//		}
//	}
//}
//
///**
//* 完成一次建堆，最大值在堆的顶部(根节点)
//*/
//void maxHeapify(int arrays[], int size) {
//
//	 //从数组的尾部开始，直到第一个元素(角标为0)
//	for (int i = size - 1; i >= 0; i--) {
//		heapify(arrays, i, size);
//	}
//
//}
//
//void heapSort(int arr[], int len) {
//	for (int i = 0; i < len; i++) {
//
//		//每次建堆就可以排除一个元素了
//		maxHeapify(arr, len - i);
//
//		//交换
//		int temp = arr[0];
//		arr[0] = arr[(len - 1) - i];
//		arr[(len - 1) - i] = temp;
//
//	}
//}
//
////归并排序
///************************************************
//*函数名称:mergearray
//*参数：a：待归并数组；first：开始下标；mid：中间下标；
//*     last：结束下标；temp：临时数组
//*说明：将有二个有序数列a[first...mid]和a[mid...last]合并
//*************************************************/
//void mergearray(int a[], int first, int mid, int last, int temp[])
//{
//	int i = first, j = mid + 1, k = 0;
//	while (i <= mid && j <= last)
//	{
//		if (a[i] <= a[j])
//			temp[k++] = a[i++];
//		else
//			temp[k++] = a[j++];
//	}
//	while (i <= mid)
//		temp[k++] = a[i++];
//
//	while (j <= last)
//		temp[k++] = a[j++];
//	for (i = 0; i < k; i++)
//		a[first + i] = temp[i];
//}
///************************************************
//*函数名称:mergesort
//*参数：a：待归并数组；first：开始下标；
//*     last：结束下标；temp：临时数组
//*说明：实现给定数组区间的二路归并排序
//*************************************************/
//void mergesort(int a[], int first, int last, int temp[])
//{
//
//	if (first < last)
//	{
//		int mid = (first + last) / 2;
//		mergesort(a, first, mid, temp);    //左边有序  
//		mergesort(a, mid + 1, last, temp); //右边有序  
//		mergearray(a, first, mid, last, temp); //再将二个有序数列合并      
//	}
//}
//
////计算排序
////arr:待排序数组，sorted_arr：排好序的数组，n：待排序数组长度
//void countSort(int *arr, int *sorted_arr, int n)
//{
//	int i;
//	int *count_arr = (int *)malloc(sizeof(int) * (MAX + 1));
//
//	//初始化计数数组   
//	memset(count_arr, 0, sizeof(int) * (MAX + 1));
//
//	//统计i的次数   
//	for (i = 0; i < n; i++)
//		count_arr[arr[i]]++;
//	//对所有的计数累加，作用是统计arr数组值和小于小于arr数组值出现的个数
//	for (i = 1; i <= MAX; i++)
//		count_arr[i] += count_arr[i - 1];
//	//逆向遍历源数组（保证稳定性），根据计数数组中对应的值填充到新的数组中   
//	for (i = n - 1; i >= 0; i--)
//	{
//		//count_arr[arr[i]]表示arr数组中包括arr[i]和小于arr[i]的总数
//		sorted_arr[count_arr[arr[i]] - 1] = arr[i];
//
//		//如果arr数组中有相同的数，arr[i]的下标减一
//		count_arr[arr[i]]--;
//	}
//	free(count_arr);
//}
//
//
//#define MAXNUM 20    //待排序数的最大个数
//#define MAX    100   //待排序数的最大值
//int sorted_arr[MAXNUM] = { 0 };
//
////计算排序
////arr:待排序数组，sorted_arr：排好序的数组，n：待排序数组长度
//void countSort(int *arr, int *sorted_arr, int n)
//{
//	int i;
//	int *count_arr = (int *)malloc(sizeof(int) * (MAX + 1));
//
//	//初始化计数数组   
//	memset(count_arr, 0, sizeof(int) * (MAX + 1));
//
//	//统计i的次数   
//	for (i = 0; i < n; i++)
//		count_arr[arr[i]]++;
//	//对所有的计数累加，作用是统计arr数组值和小于小于arr数组值出现的个数
//	for (i = 1; i <= MAX; i++)
//		count_arr[i] += count_arr[i - 1];
//	//逆向遍历源数组（保证稳定性），根据计数数组中对应的值填充到新的数组中   
//	for (i = n - 1; i >= 0; i--)
//	{
//		//count_arr[arr[i]]表示arr数组中包括arr[i]和小于arr[i]的总数
//		sorted_arr[count_arr[arr[i]] - 1] = arr[i];
//
//		//如果arr数组中有相同的数，arr[i]的下标减一
//		count_arr[arr[i]]--;
//	}
//	free(count_arr);
//}
//
//
//
//void shellSort(int A[], int len, int d) {//Shell排序
//	for (int inc = d; inc > 0; inc /= 2) {        //循环的次数为增量缩小至1的次数
//		for (int i = inc; i < len; ++i) {       //循环的次数为第一个分组的第二个元素到数组的结束
//			int j = i - inc;
//			int temp = A[i];
//			while (j >= 0 && A[j] > temp)
//			{
//				A[j + inc] = A[j];
//				j = j - inc;
//			}
//			if ((j + inc) != i)//防止自我插入
//				A[j + inc] = temp;//插入记录
//		}
//	}
//}
//
//
//void selectSort(int A[], int len) {//简单选择排序（又称直接选择排序）
//	int i, j, k;
//	for (i = 0; i < len; i++) {
//		k = i;
//		for (j = i + 1; j < len; j++) {
//			if (A[j] < A[k])
//				k = j;
//		}
//		if (i != k) {
//			A[i] = A[i] + A[k];
//			A[k] = A[i] - A[k];
//			A[i] = A[i] - A[k];
//		}
//	}
//}
//
//
////a：待排序数组，low：最低位的下标，high：最高位的下标
//void quickSort(int a[], int low, int high) {//快速排序
//	if (low >= high)
//	{
//		return;
//	}
//	int left = low;
//	int right = high;
//	int key = a[left];    /*用数组的第一个记录作为分区元素*/
//	while (left != right) {
//		while (left < right&&a[right] >= key)    /*从右向左扫描，找第一个码值小于key的记录，并交换到key*/
//			--right;
//		a[left] = a[right];
//		while (left < right&&a[left] <= key)
//			++left;
//		a[right] = a[left];    /*从左向右扫描，找第一个码值大于key的记录，并交换到右边*/
//	}
//	a[left] = key;    /*分区元素放到正确位置*/
//	quickSort(a, low, left - 1);
//	quickSort(a, left + 1, high);
//}
//void bubbleSort(int array[], int len) {//冒泡排序（升序）
//	//循环的次数为数组长度减一，剩下的一个数不需要排序
//	for (int i = 0; i < len - 1; ++i) {
//		bool noswap = true;
//		//循环次数为待排序数第一位数冒泡至最高位的比较次数
//		for (int j = 0; j < len - i - 1; ++j) {
//			if (array[j] > array[j + 1]) {
//				array[j] = array[j] + array[j + 1];//a=a+b
//				array[j + 1] = array[j] - array[j + 1];//b=a-b
//				array[j] = array[j] - array[j + 1];//a=a-b
//				noswap = false;
//			}
//		}
//		if (noswap) break;
//	}
//}
//void bubbleSort2(int array[], int len) {//冒泡排序（降序）
//	//循环的次数为数组长度减一，剩下的一个数不需要排序
//	for (int i = 0; i < len - 1; ++i) {
//		bool noswap = true;
//		//循环次数为待排序数第一位数冒泡至最高位的比较次数
//		for (int j = 0; j < len - i - 1; ++j) {
//			if (array[j] < array[j + 1]) {
//				array[j] = array[j] + array[j + 1];//a=a+b
//				array[j + 1] = array[j] - array[j + 1];//b=a-b
//				array[j] = array[j] - array[j + 1];//a=a-b
//				noswap = false;
//			}
//		}
//		if (noswap) break;
//	}
//}
//
////A：输入数组，len:数组长度
//void insertSort(int A[], int len) {//直接插入排序（升序）
//	int temp;
//	for (int i = 1; i < len; i++)
//	{
//		int j = i - 1;
//		temp = A[i];
//		//查找到要插入的位置
//		while (j >= 0 && A[j] > temp)
//		{
//			A[j + 1] = A[j];
//			j--;
//		}
//		if (j != i - 1)
//			A[j + 1] = temp;
//	}
//}
//
//void insertSort2(int A[], int len) {//直接插入排序(降序)
//	int temp;
//	for (int i = 1; i < len; i++)
//	{
//		int j = i - 1;
//		temp = A[i];
//		//查找到要插入的位置
//		while (j >= 0 && A[j] < temp)
//		{
//			A[j + 1] = A[j];
//			j--;
//		}
//		if (j != i - 1)
//			A[j + 1] = temp;
//	}
//}
//
//
////基数排序（升序）
//int GetNumInPos(int num, int pos) {//找到num的从低到高的第pos位的数据
//	int temp = 1;
//	for (int i = 0; i < pos - 1; i++)
//		temp *= 10;
//
//	return (num / temp) % 10;
//}
//
//#define RADIX_10 10    //整形排序
//#define KEYNUM_31 10     //关键字个数，这里为整形位数
//void RadixSort(int* pDataArray, int iDataNum)
//{
//	int *radixArrays[RADIX_10];    //分别为0~9的序列空间
//	for (int i = 0; i < 10; i++) {
//		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
//		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
//	}
//	for (int pos = 1; pos <= KEYNUM_31; pos++) {   //从个位开始到31位
//		for (int i = 0; i < iDataNum; i++) {   //分配过程
//			int num = GetNumInPos(pDataArray[i], pos);
//			int index = ++radixArrays[num][0];
//			radixArrays[num][index] = pDataArray[i];
//		}
//		for (int i = 0, j = 0; i < RADIX_10; i++) {    //收集
//			for (int k = 1; k <= radixArrays[i][0]; k++)
//				pDataArray[j++] = radixArrays[i][k];
//			radixArrays[i][0] = 0;    //复位
//		}
//	}
//}
////基数排序（降序）
//void RadixSort2(int* pDataArray, int iDataNum)//降序
//{
//	int *radixArrays[RADIX_10];    //分别为0~9的序列空间
//	for (int i = 0; i < 10; i++) {
//		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
//		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
//	}
//	for (int pos = 1; pos <= KEYNUM_31; pos++) {   //从个位开始到31位
//		for (int i = 0; i < iDataNum; i++) {   //分配过程
//			int num = GetNumInPos(pDataArray[i], pos);
//			int index = ++radixArrays[num][0];
//			radixArrays[num][index] = pDataArray[i];
//		}
//		for (int i = 0, j = iDataNum - 1; i < RADIX_10; i++) {    //收集
//			for (int k = radixArrays[i][0]; k >= 1; k--)
//				pDataArray[j--] = radixArrays[i][k];
//			radixArrays[i][0] = 0;    //复位
//		}
//	}
//}
//
//// 归并排序（升序）
//void mergearray(int a[], int first, int mid, int last, int temp[])
//{
//	int i = first, j = mid + 1, k = 0;
//	while (i <= mid && j <= last)
//	{
//		if (a[i] <= a[j])
//			temp[k++] = a[i++];
//		else
//			temp[k++] = a[j++];
//	}
//	while (i <= mid)
//		temp[k++] = a[i++];
//	while (j <= last)
//		temp[k++] = a[j++];
//	for (i = 0; i < k; i++)
//		a[first + i] = temp[i];
//}
//void mergesort(int a[], int first, int last, int temp[])
//{
//	if (first < last)
//	{
//		int mid = (first + last) / 2;
//		mergesort(a, first, mid, temp);    //左边有序  
//		mergesort(a, mid + 1, last, temp); //右边有序  
//		mergearray(a, first, mid, last, temp); //再将二个有序数列合并      
//	}
//}
//
//// 归并排序（降序）
//void mergearray2(int a[], int first, int mid, int last, int temp[])
//{
//	int i = first, j = mid + 1, k = 0;
//	while (i <= mid && j <= last)
//	{
//		if (a[i] > a[j])
//			temp[k++] = a[i++];
//		else
//			temp[k++] = a[j++];
//	}
//	while (i <= mid)
//		temp[k++] = a[i++];
//	while (j <= last)
//		temp[k++] = a[j++];
//	for (i = 0; i < k; i++)
//		a[first + i] = temp[i];
//}
//void mergesort2(int a[], int first, int last, int temp[])
//{
//	if (first < last)
//	{
//		int mid = (first + last) / 2;
//		mergesort2(a, first, mid, temp);    //左边有序  
//		mergesort2(a, mid + 1, last, temp); //右边有序  
//		mergearray2(a, first, mid, last, temp); //再将二个有序数列合并      
//	}
//}