package prac08_10;
import java.util.*;
import java.io.*;

class PhoneExplorer {
	String fileName = "c:\\temp\\phone.txt";
	//String fileName = "D:\\temp\\phone.txt";	//�׷� �� fileName�� �������� �ʴ� ���� �̸��� ������ �� ������ ����.
	HashMap<String, String> phoneMap = new HashMap<String, String>();
	
	private void readPhoneFile() {
		try {
			Scanner fScanner = new Scanner(new FileReader(new File(fileName)));
			while(fScanner.hasNext()) {
				String name = fScanner.next();
				String tel = fScanner.next();
				phoneMap.put(name, tel);
			}
			fScanner.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("�� " + phoneMap.size() + "���� ��ȭ��ȣ�� �о����ϴ�.");
	}
	private void processQuery() {
		Scanner scanner = new Scanner(System.in);
		while(true) {
			System.out.print("�̸�>> ");
			String name = scanner.nextLine();
			if(name.equals("�׸�"))
				break;
			String tel = phoneMap.get(name);
			if(tel == null)
				System.out.println("ã�� �̸��� �����ϴ�.");
			else
				System.out.println(tel);
		}
		scanner.close();
	}
	public void run() {
		readPhoneFile();
		processQuery();
	}
}

public class PhoneApp_20164269 {

	public static void main(String[] args) {
		PhoneExplorer phoneExplorer = new PhoneExplorer();
		phoneExplorer.run(); //������ ��ü�Լ��� ����Լ� run() ȣ��
	}
}