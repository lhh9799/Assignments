//20164344 ����Ź, 20164269 ����ȣ 
#include <stdio.h>
#include <stdlib.h>

int transform(int exponent, int n, int base) {		//exponent : ����, n : p*q, base : ��(������ ��) 
	int count = 0, index = 0, copied_exponent = exponent;
	int *binary, *mod;								//binary : ����(exponent)�� �������� �����ϴ� �迭, mod : modular���갪�� �����ϴ� �迭 
	int i, result = 1;
	
	do {
		copied_exponent /= 2;
		count++;									//�������� �Ҵ��� ������ �� ��� 
	}while(copied_exponent >= 2);
	
	binary = (int *)malloc((count+1)*sizeof(int));	//count+1 �� ��ŭ �����Ҵ� �ؾ� �Ѵ�. ex)3�� 2�� 1�� ������������, �������� ǥ���ϱ� ���ؼ��� 2�ڸ��� �ʿ��ϴ� 
	mod = (int *)malloc((count+1)*sizeof(int));
	
	//������ 2�������� ǥ�� 
	do {
		binary[index++] = exponent % 2;				//2�� ���������� �������� �迭�� ����
		exponent /= 2;
	}while(exponent !=0);							//���� 0�� �Ǹ� �ݺ��� ���� 
	
	//�Ʒ� ��ⷯ ������ ÷�ڰ� 2�� �������� ���� ���� ex) 5^1(5^2^0), 5^2(5^2^1), 5^4(5^2^2), 5^8(5^2^3)
	for(i = 0; i < index; i++) {
		mod[i] = base % n;
		base = mod[i] * mod[i];
	}
	
	//���� ��ⷯ �� ����
	for(i = 0; i < index; i++) {
		if(binary[i] != 0) {
			result = result * mod[i] % n;
		}
	}
	free(binary); free(mod);
	
	return result;
}

int EEA(int e, int phi){						//d���� ���ϱ����� Ȯ�� ��Ŭ���� �˰��� �Լ�
	int q;										// N/e ���� ������ ����
	int r[3], x[3];								// ���� ri �� xi�� ����
	r[0] = phi, r[1] = e;						// �� �迭�� �ʱⰪ ����
	x[0] = 0, x[1] = 1;							// xi�� �ʱⰪ ���� 

	while(r[2] != 1){							//�Ʒ� �Ŀ� ���� ri���� 1�� �Ǹ� ����� ������.
		q = r[0] / r[1];						// �Ź� phi/e (a/b) �� ���� 
		r[2] = r[0] - r[1] * q;					//�迭 ri �� �ش��Ѵ�. ri = ri-2 - ri-1 * qi
		printf("r2 = r0 - r1 * q : %d = %d - %d * %d\n", r[2], r[0], r[1], q); 
		r[0] = r[1];
		r[1] = r[2];							//�迭 ri�� �� == b r2�� ���� 1�� �Ǹ� ����Ż�� 
		x[2] = x[0] - x[1] * q;					//�迭 xi�� �ش��Ѵ�. r1�� ���� 1�϶� x2�� ���� d�� 
		printf("x2 = x0 - x1 * q : %d = %d - %d * %d\n\n", x[2], x[0], x[1], q); 
		x[0] = x[1];
		x[1] = x[2];							//�迭 xi�� �� == y
	}
	
	if(x[2] < 0)								//d���� ������ ���
		x[2] += phi;

	return x[2];
}

int main(int argc, char *argv[]) {
 
	int p = 29;									//RSA�˰��� ���� �� ������
	int q = 31;
	int n = p * q;
	int phi = (p-1) * (q-1);
	int e = 571;
	int d;      								//����Ű d�� ���� ���� 
	int data = 115;
	int ciphertext;								//��ȣ���� ������ ���� 
	
	d = EEA(e, phi);							//����Ű d�� ���ϱ����� Ȯ����Ŭ����˰��� �Լ� ȣ�� �Ű����� e,N 
	printf("����Ű= {%d, %d}, ����Ű = {%d, %d}\n\n",d, n, e, n);

	printf("ciphertext = %d\n", ciphertext = transform(e, n, data));	//����Ű�� �����͸� �Ű������� ��ȣ���� ���� ��ȯ�޾�  �����ϰ� ��� 
	printf("plaintext = %d\n", transform(d, n, ciphertext));			//����Ű�� ��ȣȭ�� �����͸� �Ű������� ���� ���� ��ȯ�޾� ��� 
	
	return 0;
}
