//20164344 국정탁, 20164269 이현호 
#include <stdio.h>
#include <stdlib.h>

int transform(int exponent, int n, int base) {		//exponent : 지수, n : p*q, base : 밑(데이터 값) 
	int count = 0, index = 0, copied_exponent = exponent;
	int *binary, *mod;								//binary : 지수(exponent)를 이진수로 저장하는 배열, mod : modular연산값을 저장하는 배열 
	int i, result = 1;
	
	do {
		copied_exponent /= 2;
		count++;									//동적으로 할당할 원소의 수 계산 
	}while(copied_exponent >= 2);
	
	binary = (int *)malloc((count+1)*sizeof(int));	//count+1 값 만큼 동적할당 해야 한다. ex)3은 2로 1번 나누어지지만, 이진수로 표현하기 위해서는 2자리가 필요하다 
	mod = (int *)malloc((count+1)*sizeof(int));
	
	//지수를 2진법으로 표현 
	do {
		binary[index++] = exponent % 2;				//2로 나누었을때 나머지를 배열에 저장
		exponent /= 2;
	}while(exponent !=0);							//몫이 0이 되면 반복을 끝냄 
	
	//아래 모듈러 연산은 첨자가 2의 지수승인 수만 연산 ex) 5^1(5^2^0), 5^2(5^2^1), 5^4(5^2^2), 5^8(5^2^3)
	for(i = 0; i < index; i++) {
		mod[i] = base % n;
		base = mod[i] * mod[i];
	}
	
	//최종 모듈러 값 연산
	for(i = 0; i < index; i++) {
		if(binary[i] != 0) {
			result = result * mod[i] % n;
		}
	}
	free(binary); free(mod);
	
	return result;
}

int EEA(int e, int phi){						//d값을 구하기위한 확장 유클리드 알고리즘 함수
	int q;										// N/e 값을 저장할 변수
	int r[3], x[3];								// 각각 ri 와 xi를 저장
	r[0] = phi, r[1] = e;						// 각 배열에 초기값 저장
	x[0] = 0, x[1] = 1;							// xi의 초기값 저장 

	while(r[2] != 1){							//아래 식에 따라 ri값이 1이 되면 계산을 끝낸다.
		q = r[0] / r[1];						// 매번 phi/e (a/b) 값 저장 
		r[2] = r[0] - r[1] * q;					//배열 ri 에 해당한다. ri = ri-2 - ri-1 * qi
		printf("r2 = r0 - r1 * q : %d = %d - %d * %d\n", r[2], r[0], r[1], q); 
		r[0] = r[1];
		r[1] = r[2];							//배열 ri의 값 == b r2의 값이 1이 되면 루프탈출 
		x[2] = x[0] - x[1] * q;					//배열 xi에 해당한다. r1의 값이 1일때 x2의 값이 d값 
		printf("x2 = x0 - x1 * q : %d = %d - %d * %d\n\n", x[2], x[0], x[1], q); 
		x[0] = x[1];
		x[1] = x[2];							//배열 xi의 값 == y
	}
	
	if(x[2] < 0)								//d값이 음수인 경우
		x[2] += phi;

	return x[2];
}

int main(int argc, char *argv[]) {
 
	int p = 29;									//RSA알고리즘에 사용될 각 변수들
	int q = 31;
	int n = p * q;
	int phi = (p-1) * (q-1);
	int e = 571;
	int d;      								//개인키 d를 넣을 변수 
	int data = 115;
	int ciphertext;								//암호문을 저장할 변수 
	
	d = EEA(e, phi);							//개인키 d를 구하기위한 확장유클리드알고리즘 함수 호출 매개변수 e,N 
	printf("개인키= {%d, %d}, 공개키 = {%d, %d}\n\n",d, n, e, n);

	printf("ciphertext = %d\n", ciphertext = transform(e, n, data));	//공개키와 데이터를 매개변수로 암호문을 구해 반환받아  저장하고 출력 
	printf("plaintext = %d\n", transform(d, n, ciphertext));			//개인키와 암호화된 데이터를 매개변수로 평문을 구해 반환받아 출력 
	
	return 0;
}
