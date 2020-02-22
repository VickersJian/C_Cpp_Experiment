////������
///**
//	 * ����
//	 *
//	 * @param arrays          ��������ȫ������
//	 * @param currentRootNode ��ǰ���ڵ�λ��
//	 * @param size            �ڵ�����
//	 */
//void heapify(int arrays[], int currentRootNode, int size) {
//
//	if (currentRootNode < size) {
//		//����������������λ��
//		int left = 2 * currentRootNode + 1;
//		int right = 2 * currentRootNode + 2;
//
//		//�ѵ�ǰ���ڵ�λ�ÿ���������
//		int max = currentRootNode;
//
//		if (left < size) {
//			//����ȵ�ǰ��Ԫ��Ҫ�󣬼�¼����λ��
//			if (arrays[max] < arrays[left]) {
//				max = left;
//			}
//		}
//		if (right < size) {
//			//����ȵ�ǰ��Ԫ��Ҫ�󣬼�¼����λ��
//			if (arrays[max] < arrays[right]) {
//				max = right;
//			}
//		}
//		//������Ĳ��Ǹ�Ԫ��λ�ã���ô�ͽ���
//		if (max != currentRootNode) {
//			int temp = arrays[max];
//			arrays[max] = arrays[currentRootNode];
//			arrays[currentRootNode] = temp;
//
//			�����Ƚϣ�ֱ�����һ�ν���
//			heapify(arrays, max, size);
//		}
//	}
//}
//
///**
//* ���һ�ν��ѣ����ֵ�ڶѵĶ���(���ڵ�)
//*/
//void maxHeapify(int arrays[], int size) {
//
//	 //�������β����ʼ��ֱ����һ��Ԫ��(�Ǳ�Ϊ0)
//	for (int i = size - 1; i >= 0; i--) {
//		heapify(arrays, i, size);
//	}
//
//}
//
//void heapSort(int arr[], int len) {
//	for (int i = 0; i < len; i++) {
//
//		//ÿ�ν��ѾͿ����ų�һ��Ԫ����
//		maxHeapify(arr, len - i);
//
//		//����
//		int temp = arr[0];
//		arr[0] = arr[(len - 1) - i];
//		arr[(len - 1) - i] = temp;
//
//	}
//}
//
////�鲢����
///************************************************
//*��������:mergearray
//*������a�����鲢���飻first����ʼ�±ꣻmid���м��±ꣻ
//*     last�������±ꣻtemp����ʱ����
//*˵�������ж�����������a[first...mid]��a[mid...last]�ϲ�
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
//*��������:mergesort
//*������a�����鲢���飻first����ʼ�±ꣻ
//*     last�������±ꣻtemp����ʱ����
//*˵����ʵ�ָ�����������Ķ�·�鲢����
//*************************************************/
//void mergesort(int a[], int first, int last, int temp[])
//{
//
//	if (first < last)
//	{
//		int mid = (first + last) / 2;
//		mergesort(a, first, mid, temp);    //�������  
//		mergesort(a, mid + 1, last, temp); //�ұ�����  
//		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�      
//	}
//}
//
////��������
////arr:���������飬sorted_arr���ź�������飬n�����������鳤��
//void countSort(int *arr, int *sorted_arr, int n)
//{
//	int i;
//	int *count_arr = (int *)malloc(sizeof(int) * (MAX + 1));
//
//	//��ʼ����������   
//	memset(count_arr, 0, sizeof(int) * (MAX + 1));
//
//	//ͳ��i�Ĵ���   
//	for (i = 0; i < n; i++)
//		count_arr[arr[i]]++;
//	//�����еļ����ۼӣ�������ͳ��arr����ֵ��С��С��arr����ֵ���ֵĸ���
//	for (i = 1; i <= MAX; i++)
//		count_arr[i] += count_arr[i - 1];
//	//�������Դ���飨��֤�ȶ��ԣ������ݼ��������ж�Ӧ��ֵ��䵽�µ�������   
//	for (i = n - 1; i >= 0; i--)
//	{
//		//count_arr[arr[i]]��ʾarr�����а���arr[i]��С��arr[i]������
//		sorted_arr[count_arr[arr[i]] - 1] = arr[i];
//
//		//���arr����������ͬ������arr[i]���±��һ
//		count_arr[arr[i]]--;
//	}
//	free(count_arr);
//}
//
//
//#define MAXNUM 20    //����������������
//#define MAX    100   //�������������ֵ
//int sorted_arr[MAXNUM] = { 0 };
//
////��������
////arr:���������飬sorted_arr���ź�������飬n�����������鳤��
//void countSort(int *arr, int *sorted_arr, int n)
//{
//	int i;
//	int *count_arr = (int *)malloc(sizeof(int) * (MAX + 1));
//
//	//��ʼ����������   
//	memset(count_arr, 0, sizeof(int) * (MAX + 1));
//
//	//ͳ��i�Ĵ���   
//	for (i = 0; i < n; i++)
//		count_arr[arr[i]]++;
//	//�����еļ����ۼӣ�������ͳ��arr����ֵ��С��С��arr����ֵ���ֵĸ���
//	for (i = 1; i <= MAX; i++)
//		count_arr[i] += count_arr[i - 1];
//	//�������Դ���飨��֤�ȶ��ԣ������ݼ��������ж�Ӧ��ֵ��䵽�µ�������   
//	for (i = n - 1; i >= 0; i--)
//	{
//		//count_arr[arr[i]]��ʾarr�����а���arr[i]��С��arr[i]������
//		sorted_arr[count_arr[arr[i]] - 1] = arr[i];
//
//		//���arr����������ͬ������arr[i]���±��һ
//		count_arr[arr[i]]--;
//	}
//	free(count_arr);
//}
//
//
//
//void shellSort(int A[], int len, int d) {//Shell����
//	for (int inc = d; inc > 0; inc /= 2) {        //ѭ���Ĵ���Ϊ������С��1�Ĵ���
//		for (int i = inc; i < len; ++i) {       //ѭ���Ĵ���Ϊ��һ������ĵڶ���Ԫ�ص�����Ľ���
//			int j = i - inc;
//			int temp = A[i];
//			while (j >= 0 && A[j] > temp)
//			{
//				A[j + inc] = A[j];
//				j = j - inc;
//			}
//			if ((j + inc) != i)//��ֹ���Ҳ���
//				A[j + inc] = temp;//�����¼
//		}
//	}
//}
//
//
//void selectSort(int A[], int len) {//��ѡ�������ֳ�ֱ��ѡ������
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
////a�����������飬low�����λ���±꣬high�����λ���±�
//void quickSort(int a[], int low, int high) {//��������
//	if (low >= high)
//	{
//		return;
//	}
//	int left = low;
//	int right = high;
//	int key = a[left];    /*������ĵ�һ����¼��Ϊ����Ԫ��*/
//	while (left != right) {
//		while (left < right&&a[right] >= key)    /*��������ɨ�裬�ҵ�һ����ֵС��key�ļ�¼����������key*/
//			--right;
//		a[left] = a[right];
//		while (left < right&&a[left] <= key)
//			++left;
//		a[right] = a[left];    /*��������ɨ�裬�ҵ�һ����ֵ����key�ļ�¼�����������ұ�*/
//	}
//	a[left] = key;    /*����Ԫ�طŵ���ȷλ��*/
//	quickSort(a, low, left - 1);
//	quickSort(a, left + 1, high);
//}
//void bubbleSort(int array[], int len) {//ð����������
//	//ѭ���Ĵ���Ϊ���鳤�ȼ�һ��ʣ�µ�һ��������Ҫ����
//	for (int i = 0; i < len - 1; ++i) {
//		bool noswap = true;
//		//ѭ������Ϊ����������һλ��ð�������λ�ıȽϴ���
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
//void bubbleSort2(int array[], int len) {//ð�����򣨽���
//	//ѭ���Ĵ���Ϊ���鳤�ȼ�һ��ʣ�µ�һ��������Ҫ����
//	for (int i = 0; i < len - 1; ++i) {
//		bool noswap = true;
//		//ѭ������Ϊ����������һλ��ð�������λ�ıȽϴ���
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
////A���������飬len:���鳤��
//void insertSort(int A[], int len) {//ֱ�Ӳ�����������
//	int temp;
//	for (int i = 1; i < len; i++)
//	{
//		int j = i - 1;
//		temp = A[i];
//		//���ҵ�Ҫ�����λ��
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
//void insertSort2(int A[], int len) {//ֱ�Ӳ�������(����)
//	int temp;
//	for (int i = 1; i < len; i++)
//	{
//		int j = i - 1;
//		temp = A[i];
//		//���ҵ�Ҫ�����λ��
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
////������������
//int GetNumInPos(int num, int pos) {//�ҵ�num�Ĵӵ͵��ߵĵ�posλ������
//	int temp = 1;
//	for (int i = 0; i < pos - 1; i++)
//		temp *= 10;
//
//	return (num / temp) % 10;
//}
//
//#define RADIX_10 10    //��������
//#define KEYNUM_31 10     //�ؼ��ָ���������Ϊ����λ��
//void RadixSort(int* pDataArray, int iDataNum)
//{
//	int *radixArrays[RADIX_10];    //�ֱ�Ϊ0~9�����пռ�
//	for (int i = 0; i < 10; i++) {
//		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
//		radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
//	}
//	for (int pos = 1; pos <= KEYNUM_31; pos++) {   //�Ӹ�λ��ʼ��31λ
//		for (int i = 0; i < iDataNum; i++) {   //�������
//			int num = GetNumInPos(pDataArray[i], pos);
//			int index = ++radixArrays[num][0];
//			radixArrays[num][index] = pDataArray[i];
//		}
//		for (int i = 0, j = 0; i < RADIX_10; i++) {    //�ռ�
//			for (int k = 1; k <= radixArrays[i][0]; k++)
//				pDataArray[j++] = radixArrays[i][k];
//			radixArrays[i][0] = 0;    //��λ
//		}
//	}
//}
////�������򣨽���
//void RadixSort2(int* pDataArray, int iDataNum)//����
//{
//	int *radixArrays[RADIX_10];    //�ֱ�Ϊ0~9�����пռ�
//	for (int i = 0; i < 10; i++) {
//		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
//		radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
//	}
//	for (int pos = 1; pos <= KEYNUM_31; pos++) {   //�Ӹ�λ��ʼ��31λ
//		for (int i = 0; i < iDataNum; i++) {   //�������
//			int num = GetNumInPos(pDataArray[i], pos);
//			int index = ++radixArrays[num][0];
//			radixArrays[num][index] = pDataArray[i];
//		}
//		for (int i = 0, j = iDataNum - 1; i < RADIX_10; i++) {    //�ռ�
//			for (int k = radixArrays[i][0]; k >= 1; k--)
//				pDataArray[j--] = radixArrays[i][k];
//			radixArrays[i][0] = 0;    //��λ
//		}
//	}
//}
//
//// �鲢��������
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
//		mergesort(a, first, mid, temp);    //�������  
//		mergesort(a, mid + 1, last, temp); //�ұ�����  
//		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�      
//	}
//}
//
//// �鲢���򣨽���
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
//		mergesort2(a, first, mid, temp);    //�������  
//		mergesort2(a, mid + 1, last, temp); //�ұ�����  
//		mergearray2(a, first, mid, last, temp); //�ٽ������������кϲ�      
//	}
//}