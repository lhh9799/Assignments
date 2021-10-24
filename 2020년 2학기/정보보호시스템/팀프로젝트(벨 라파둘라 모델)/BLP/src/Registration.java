import java.io.*;
import javax.swing.JOptionPane;		//메시지 박수 출력용

//회원가입을 위한 메소드들을 정의한 class
public class Registration {
	
	//회원가입 메소드
	public void register(String ID, String PW) {
		//지정 텍스트 파일에 회원가입한 회원의 정보를 저장
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("MemberInfo.txt", true));	//false : 파일이 이미 존재하는 경우 파일을 덮어씀
			PrintWriter pw = new PrintWriter(bw, true);										//true : 생성된 파일의 뒤에 이어서 씀
			pw.write(ID + "\t" + PW + "\t" + "3" + System.getProperty("line.separator"));	//생성된 회원의 권한을 3으로 설정
			bw.close();																		//스트림 닫음
		}
		//파일을 찾지 못한 경우
		catch (FileNotFoundException e) {		//파일을 찾지 못한 오류
			JOptionPane.showMessageDialog(null, "파일을 열 수 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		//파일 입출력 관련 오류가 난 경우
		catch (IOException e) {					//파일 IO 오류
			JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	//ID 중복확인 메소드 - 중복일 경우 true를 아닐 경우 false 리턴
	public boolean redundancyCheck(String ID) {
		try {
			File info = new File("MemberInfo.txt");							//회원정보 파일 경로
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(info), "UTF-8"));	//한글을 읽기 위해 "UTF-8"로 인코딩
			
			String currentLine;
			//회원정보 파일에 추가하고자 하는 ID가 존재하는지 확인 (존재하면 중복이므로 true 리턴)
			while((currentLine = br.readLine()) != null){
				if(currentLine.contains(ID)) {								//읽어온 줄에서 일치하는 ID를 찾은 경우
					if(ID.equals(currentLine.split("\t")[0])) {	
						br.close();
						return true;
					}
				}
			}
			br.close();		
		}
		catch (FileNotFoundException exc) {									//파일을 찾지 못한 오류
			JOptionPane.showMessageDialog(null, "파일을 열 수 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException exc) {											//파일 IO 오류
			JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		return false;
	}
}