package prac03_08;
import java.util.Scanner;

public class RandomArray_20164269 {

	public static boolean exists(int a[], int to, int r) {
		for (int j=0; j<to; j++)
			if (a[j] == r)
				return true; //a[j]가 r과 같을 경우
			return false; //동일한 것이 하나도 없는 경우
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("정수 몇개?");
		int n = scanner.nextInt();
		
		if((n<1) || (n>100)) {
				System.out.print("1~100사이로 입력하세요!");
				scanner.close();
				return;
		}
		
		int array [] = new int [n]; //동적으로 배열 생성
		
		for(int i=0; i<array.length; i++) //배열 초기화	
			array[i] = 0;
		
		for (int i=0; i<array.length; i++) {
			int r = (int)(Math.random()*100 + 1);
			
			if (exists(array, i, r)) {
				i--; //동일한 값이 있을 경우 i값 감소
			continue;
			}
			array[i] = r; // r을 array[i]에 저장
		}
		for (int i=0; i<array.length; i++) {
			System.out.print(array[i]+" ");
			if((i+1)%10 == 0) //배열의 수가 10이상인 경우 10개씩 출력 후 줄바꿈
				System.out.println();
		}
		scanner.close();
	}
}