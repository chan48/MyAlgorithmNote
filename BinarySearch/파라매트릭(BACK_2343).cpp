#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 100000000
using namespace std;

int cmp(int length, int partN, vector<int>& les)
{
	int tot = 0;
	int partial = 0;
	int cnt = 1;
	int i;
	for (i = 0; i < les.size();i++) {
		if (partial + les[i] > length)
		{
			if (les[i] > length) return 0;
			partial = les[i];
			cnt++;
		}
		else partial += les[i];
	}
	if (partN >= cnt) return 1; //length�� partN�� ����
	else return 0; //length�� �ʹ� ����
}


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> lesson(N);
	for (int i = 0; i < N; i++) scanf("%d", &lesson[i]);
	

	int left = 0;
	int right = MAX;
	int mid;
	int min = 1 << 30;

	while (left<=right) {
		mid = (left + right) / 2;
		//������ ������ ��� -> �� ���� ���� ã�ƺ���.
		int condition = cmp(mid, M,lesson);		
		if(condition==1){
			min = (min < mid) ? min : mid;
			right = mid - 1;
		}
		//��緹�� �ð��� �ʹ� ª�Ƽ� mid�� ������.
		else
		{
			left = mid + 1;
		}
	}
	printf("%d\n", min);
	
	


	return 0;
}