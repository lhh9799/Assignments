#include <cctype>	//isalpha �Լ��� ����ϱ� ���� �������(A~Z: 1, a~z: 2, �� ��: 0 ����)
#include <string>	//getline �Լ��� ����ϱ� ���� �������(����(" ")�� �Է¹޵���)
#include <map>		//map Ŭ������ ����ϱ� ���� �������(�� ��尡 key�� value ������ �̷���� Ʈ��. �ߺ��� ������� ����. �������� ����)
#include <algorithm>//min, max �Լ��� ����ϱ� ���� �������
#include <ctime>	//�ڵ� ����ð� ������ ���� �������
#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
using namespace std;//ǥ�� �̸������� �����

int main() {
	string str1, str2, temp = "";				//str1, str2: �Է¹��� ���ڿ� / temp: �κ����տ� �߰��� ���ڿ�
	map<string, int> map1, map2;				//map1, map2: str1, str2���� ��ȿ�� ���ڿ�(���� ���ĺ�)�� ������ �����ϴ� ��
	map<string, int> intersection, union_set;	//intersection: ������ ��, union_set: ������ ��
	int intersection_count = 0;					//�κ������� ������ ��
	int union_count = 0;						//�������� ������ ��
	int answer = 65536;							//��ī�� ���絵(���� A�� ���� B�� ��� �������� ��쿡�� �������� ���ǵ��� ������ ���� J(A, B) = 1�� �����Ѵ�.) -> 1 * 65536

	//�� ���ڿ� �Է¹���
	getline(cin, str1);
	getline(cin, str2);

	clock_t start = clock();	//���� �ð� ����

	for(unsigned int i=0; i<str1.length()-1; i++) {		//str1���� - 1���� �ݺ�(i+1������ �����ϱ� ����)
		if(isalpha(str1[i]) && isalpha(str1[i+1])) {	//�� ���� ��� ���ĺ��̸�
			temp = tolower(str1[i]);					//ù ��° ���ڸ� �ҹ��ڷ� �ٲ�
			temp += tolower(str1[i+1]);					//�� ��° ���ڸ� �ҹ��ڷ� �ٲ۵� ���ڿ��� �߰�
			map1[temp]++;								//���� value ����
		}
	}

	for(unsigned int i=0; i<str2.length()-1; i++) {		//str2���� - 1���� �ݺ�(i+1������ �����ϱ� ����)
		if(isalpha(str2[i]) && isalpha(str2[i+1])) {	//�� ���� ��� ���ĺ��̸�
			temp = tolower(str2[i]);					//ù ��° ���ڸ� �ҹ��ڷ� �ٲ�
			temp += tolower(str2[i+1]);					//�� ��° ���ڸ� �ҹ��ڷ� �ٲ۵� ���ڿ��� �߰�
			map2[temp]++;								//���� value ����
		}
	}

	/*
	 *[������ ã��]
	 *�ߺ��� ���� ã���� �ǹǷ� ��� ���� �������� �񱳸� �ص� �������
	 *���̰� ª�� ���� �������� ���ϸ� �� �ʿ� ���Ұ� �����ְ�����, �� �̻� ª�� �ʿ� ���� �����Ƿ� �ߺ��� �� ����(�� ��� ����)
	 */
	for(auto it : map1) {											//map1�� ��� key�� ������ ��ȸ
		int map1_count = map1.find(it.first)->second;				//map1�� �ִ� ��ȿ�� ���ڿ��� ������ map1_count�� ����

		if(map2.find(it.first) != map2.end()) {						//find�Լ��� Ű ���� �������� ������ end�� ������ -> find�� ���ϰ��� end()�� �ƴϸ�
			int map2_count = map2.find(it.first)->second;			//map2�� �ִ� map1�� ��ȿ�� ���ڿ��� ������ map2_count�� ����
			int duplication_count = min(map1_count, map2_count);	//�������̹Ƿ� "�ּڰ�"�� duplication_count�� ����

			intersection[it.first] = duplication_count;				//�� �� �� �� ������ �ִ� �κ����� ���� ����(���ڿ�, ����)
			intersection_count += duplication_count;				//������ ������ �� ����(���������̹Ƿ� 1���� �ƴ� duplication_count�� ���ؾ� ��)
		}
	}

	/*
	 *[������ ã��]
	 *1. map1�� map2�� ���� �Ѱ��� ��� ����(map �����̳��̹Ƿ� key���� �ߺ��ؼ� ���� ����)
	 *2. map1�� �ش� ���Ұ� �� �� �����ϴ��� �˻�
	 *3. map2�� �ش� ���Ұ� �� �� �����ϴ��� �˻�
	 *4. �� �� ū ���� �����տ� ����(key: ���ڿ�, value: ����)
	 */
	union_set.insert(map1.begin(), map1.end());
	union_set.insert(map2.begin(), map2.end());
	for(auto it : union_set) {								//�������� ��� key�� ������ ��ȸ
		int map1_count = 0, map2_count = 0;					//�ִ��� ã�ƾ� �ϹǷ� �Ź� 0���� �ʱ�ȭ(0�� �ش� ���� ������ �ǹ�)

		//�Ʒ� �� if�� �� �ϳ��� �ݵ�� �����(union_set�� �����ϴ� ���� map1, map2���� �����Ա� ����)
		if(map1.find(it.first) != map1.end())				//find�Լ��� Ű ���� �������� ������ end�� ������ -> find�� ���ϰ��� end()�� �ƴϸ�
			map1_count = map1.find(it.first)->second;		//map1�� �����ϴ� �ش� ������ �� map1_count�� ����

		if(map2.find(it.first) != map2.end())				//find�Լ��� Ű ���� �������� ������ end�� ������ -> find�� ���ϰ��� end()�� �ƴϸ�
			map2_count = map2.find(it.first)->second;		//map2�� �����ϴ� �ش� ������ �� map2_count�� ����

		int duplication_count = max(map1_count, map2_count);//�������̹Ƿ� "�ִ�"�� duplication_count�� ����
		union_set[it.first] = duplication_count;			//������ map�� value ����
		union_count += duplication_count;					//������ ������ �� ����(���������̹Ƿ� 1���� �ƴ� duplication_count�� ���ؾ� ��)
	}

	if(union_count != 0)	//�������� �����Ѵٸ� ��ī�� ���絵�� ���
		//65536 * intersection_count(�ִ�: 999) -> 65,470,464 -> int������ Ŀ�� ����
		answer = 65536 * intersection_count / union_count;	//��ī�� ���絵 * 65536 -> �Ҽ��� �Ʒ� ����

	cout << answer << endl;	//������ ���

	clock_t end = clock();	//���� �ð� ����
	cout << "����ð�: " << (double)(end - start) / CLOCKS_PER_SEC << "��";	//����ð�(����: ��) ���

	return 0;				//�����Լ��� ���������� ����
}
