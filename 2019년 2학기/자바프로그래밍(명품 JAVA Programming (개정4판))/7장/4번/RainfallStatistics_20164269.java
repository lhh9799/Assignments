package prac07_04;
import java.util.*;
//�ּ� �߰��ϱ�

public class RainfallStatistics_20164269 {
	
	public static void print(Vector v) {
		int sum = 0;
		Iterator<Integer> it = v.iterator();
		while(it.hasNext()) {
			int n = it.next();
			System.out.print(n + " ");
			sum += n;
		}
		System.out.print("\n���� ��� " + sum/v.size() + "\n");
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Vector<Integer> v = new Vector<Integer>();
		while(true) {
			System.out.print("������ �Է� (0�Է½� ����)>> ");
			int n = scanner.nextInt();
			if(n == 0)
				break;
			else {
				v.add(n);
				print(v);
			}
		}
		scanner.close();
	}
}