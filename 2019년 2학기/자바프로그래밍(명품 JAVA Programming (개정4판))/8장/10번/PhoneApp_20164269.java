package prac08_10;
import java.util.*;
import java.io.*;

class PhoneExplorer {
	String fileName = "c:\\temp\\phone.txt";
	//String fileName = "D:\\temp\\phone.txt";	//그런 후 fileName에 존재하지 않는 파일 이름을 지정한 후 실행해 보라.
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
		System.out.println("총 " + phoneMap.size() + "개의 전화번호를 읽었습니다.");
	}
	private void processQuery() {
		Scanner scanner = new Scanner(System.in);
		while(true) {
			System.out.print("이름>> ");
			String name = scanner.nextLine();
			if(name.equals("그만"))
				break;
			String tel = phoneMap.get(name);
			if(tel == null)
				System.out.println("찾는 이름이 없습니다.");
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
		phoneExplorer.run(); //생성된 객체함수의 멤버함수 run() 호출
	}
}