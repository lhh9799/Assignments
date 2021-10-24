#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
using namespace std;//ǥ�� �̸������� �����

//�Ҽ����� �ƴ����� �Ǻ��ϴ� �Լ�, �����佺�׳׽��� ü �˰����� ������ �Լ��� ���ǵ� Ŭ����
class Sieve {
public:
	int maximumValue;		//ü�� �ִ�
	vector<bool> isPrime;	//�Ҽ����� �ƴ����� �����ϴ� isPrime ���� ����

	//maximumValue�� �Ű������� �޴� ������
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;				//�Ű������� ���� maximumValue�� ������� maximumValue�� ����
		this->isPrime.assign(maximumValue + 1, false);	//���� ���͸� ����� false���� (maximumValue + 1)�� ������ ���ͷ� �ʱ�ȭ(ũ�⸦ maximumValue�� �����ϸ� maximumValue-1�� �ε��������� �����Ǳ� ����)
		this->fillSieve();								//�����佺�׳׽��� ü �˰����� ������ ����Լ� ����
	}

	//�Ҽ����� �ƴ����� �����ϴ� �Լ�
	bool isPrimeNumber(int num) const {	//�Լ��� ���� const�� �ǹ�: �ش� �Լ����� ��������� �б⸸ ��
		return this->isPrime[num];		//�Ҽ����� �ƴ����� �����ϴ� isPrime������ index ���� ���� ����
	}

	//�����佺�׳׽��� ü �˰����� �����ϴ� �Լ�
	bool fillSieve() {
		isPrime.assign(this->maximumValue, true);	//���� ���͸� ����� true���� maximumValue�� ������ ���ͷ� �ʱ�ȭ
		isPrime[0] = isPrime[1] = false;			//0�� 1�� �Ҽ��� �ƴϹǷ�(�Ҽ��� ����) false���� ����

		for(int num=2; num<=maximumValue; num++) {	//0�� 1�� ����� �ʿ䰡 �����Ƿ� 2���� ����. �ִ��� maximumValue���� �ݺ�
			if(isPrime[num] == false) {				//num�� �Ҽ��� �ƴ϶��
				continue;							//�ٽ� �Ҽ����� �Ǻ��� �ʿ䰡 �����Ƿ� �Ʒ� for���� �ǳʶ�
			}
			//�� if������ num�� �Ҽ��� �ƴ� ���� �ɷ��� => num�� �Ҽ� => num�� ������� �ٽ� �ɷ����� ��
			//num * num �̸��� ������ ���� �ݺ������� �̹� �ɷ�����
			//���� num * num���� maximumValue ���� mul�� num��ŭ ������Ű�� �Ҽ� �˻縦 �����Ѵ�
			for(long long mul = (long long) num * num; mul <= maximumValue; mul+=num) {	//mul�� num * num���� �ʱ�ȭ��. num(maximumValue)�� 1000000 ������ ���̹Ƿ� mul�� �ִ��� 1000000000000(1��)��
																						//���� mul�� �� 21����� ǥ�� ������ int�� �ƴ� �� 922����� ǥ�� ������ long long ���� �����ؾ� ��
				int index = (int)mul;				//mul <= maximumValue ���Ѷ����� mul�� int�� ������ �Ѿ�� �ʾҴ�. ������ long long���� ������ ������ num*num�� ������ �� �Ͻ������� int�� ������ ��� �� �־��� ����
													//mul�� int�� ����� ĳ�����Ͽ� int�� index�� ����
				isPrime[index] = false;				//index�� '�Ҽ��� �ƴ�'���� ����
			}
		}
	}
};

//from �̻� to ������ �� �� �Ҽ��� ���� ���Ϳ� ������ �����ϴ� �Լ�
vector<int> getAllPrimeNumbers(int from, int to, const Sieve &sieve) {
	vector<int> primes;					//�Ҽ��� ������ ���� primes ����

	for(int num=from; num<=to; num++) {	//����ڰ� �Է��� L�� R���̸� ��ȸ�ϸ�
		if(sieve.isPrimeNumber(num)) {	//num�� �Ҽ����
			primes.push_back(num);		//primes������ �� �ڿ� num�� ����
		}
	}

	return primes;						//�Ҽ����� ������ ���͸� ����
}

void process(int caseIndex, const Sieve &sieve) {
	int L, R;							//�Ҽ��� ������ �� ����. L: ���۰�, R: ����
	scanf("%d %d", &L, &R);				//���۰�, ������ �Է¹���

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);	//L �̻� R ������ �� �� �Ҽ��� ���� allPrimeNumbers ���Ϳ� ����

	printf("Case #%d:\n", caseIndex);	//�׽�Ʈ���̽��� ��ȣ�� ���
	printf("%d\n", (int)allPrimeNumbers.size());	//L �̻� R ������ �� �� �Ҽ��� ���� ������ ���
}

int main() {
	const int MAX_VALUE = 1000000;	//R�� �ִ��� 1000000�� const ����� ����(���� ������ �� ����)
	Sieve sieve = Sieve(MAX_VALUE);	//MAX_VALUE�� ���ڷ� Sieve�� �ν��Ͻ� sieve ����

	int caseSize;					//�׽�Ʈ ���̽��� ��
	scanf("%d", &caseSize);			//�׽�Ʈ ���̽��� ���� �Է¹���

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ�. ����� Case #1���� �����ϱ� ���� �ʱⰪ�� 1, ������ caseSize ���Ϸ� ����
		process(caseIndex, sieve);	//caseIndex�� ���ڷ� process �Լ� ����
	}

	return 0;						//�����Լ��� ���������� ����
}
