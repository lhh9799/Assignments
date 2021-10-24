import java.io.*;
import javax.swing.JOptionPane;

//로그인 관련 동작 함수를 가지고 있는 class
public class Login {
	static int authority;
	static String id;

	//회원정보 파일에서 일치하는 정보를 찾은 경우 true, 찾지 못한 경우 false 리턴
	public boolean verify(String ID, String PW) {
		String STR;
		String tokens[];
		
		try {
			File file = new File("MemberInfo.txt");
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file), "UTF-8"));	//한글을 읽기 위해 "UTF-8"로 인코딩
			
			while((STR = br.readLine()) != null) {
				if(STR.contains(ID)) {									//유사한 ID를 찾은 경우
					tokens = STR.split("\t");							//토큰 자름 - 0번 : 아이디 1번 : 비밀번호, 2번 : 권한
					if(ID.equals(tokens[0]) && PW.equals(tokens[1])) {	//아이디와 비밀번호가 일치하는 경우
						id = tokens[0];									//static변수인 ID에 로그인한 회원의 ID 저장
						authority = Integer.parseInt(tokens[2]);		//static변수인 authority에 로그인한 회원의 권한을 저장
						br.close();										//스트림 닫음
						return true;									
					}
				}
			}
			br.close();	//스트림 닫음
		return false;
		}
		catch (FileNotFoundException e) {								//파일을 찾지 못한 오류
			JOptionPane.showMessageDialog(null, "회원정보 파일 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException e) {											//파일 IO 오류
			JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		return false;
	}
}
