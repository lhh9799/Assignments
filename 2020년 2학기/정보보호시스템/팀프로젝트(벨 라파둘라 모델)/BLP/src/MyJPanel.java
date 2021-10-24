import javax.swing.*;
import java.util.Stack;

//패키지의 모든 Activity들을 관리하기 위한 클래스
class MyJPanel extends JFrame {
	private Stack<String> ActivityStack = new Stack<>();	//실행된 화면의 순서를 기록하기 위한 스택
	
	LoginActivity LoginActivity = null;
	MainActivity MainActivity = null;
	WritingActivity WritingActivity = null;
	ReadingActivity ReadingActivity = null;
	RegistrationActivity RegistrationActivity = null;
	AuthorizationActivity AuthorizationActivity = null;
	
	public MyJPanel() {
		LoginActivity			=	new LoginActivity(this);
		MainActivity			=	new MainActivity(this);
		WritingActivity			=	new WritingActivity(this);
		ReadingActivity			=	new ReadingActivity(this);
		RegistrationActivity	=	new RegistrationActivity(this);
		AuthorizationActivity	=	new AuthorizationActivity(this);
		
		setTitle("Bell-LaPadula model");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(1100, 650);
		setResizable(false);
		setVisible(true);
		add(LoginActivity);
	}
	
	//화면을 전환시켜주는 메소드
	public void change(String panelName, String caller) {
		ActivityStack.push(caller);				//change 메소드를 부른 액티비티의 이름을 스택에 저장
		System.out.println("(push) " + panelName);
		getContentPane().removeAll();			//컨테이너의 모든 컴포넌트 제거
		switch(panelName) {
		//프로그램이 시작하면 모든 Activity들이 단 한 번 동적할당 되기 때문에(각 Activity들을 재사용 하기 때문에) 추가적인 설정이 필요한 Activity들은 init()메소드를 가지고 있다. 
			case "LoginActivity" : 											getContentPane().add(LoginActivity);			break;
			case "RegistrationActivity" : 									getContentPane().add(RegistrationActivity);		break;
			case "MainActivity" : 			MainActivity.init();			getContentPane().add(MainActivity);				break;
			case "AuthorizationActivity" : 	AuthorizationActivity.init();	getContentPane().add(AuthorizationActivity);	break;
			case "WritingActivity" : 		WritingActivity.init();			getContentPane().add(WritingActivity);			break;
			case "ReadingActivity" : 		ReadingActivity.init(); 		getContentPane().add(ReadingActivity);			break;
		}
		revalidate();							//배치관리자가 컴포넌트들을 다시 배치하도록 함
		repaint();								//컨테이너를 다시 그림
	}	
	
	//로그아웃 메소드
	public void logout() {
		Login.authority = 0;					//로그인한 계정의 권한을 0으로 초기화
		getContentPane().removeAll();		getContentPane().add(LoginActivity);	revalidate();	repaint();
		ActivityStack.clear();					//스택 초기화
		System.out.println("(clear) ActivityStack");
	}
	
	//이전 화면으로 되돌아가는 메소드 (뒤로가기 기능을 함). 뒤로가기의 경우 로그인정보가 바뀌지 않았으므로 정보를 다시 설정해 줄 필요가 없다.
	public void goback() {
		String panelName = ActivityStack.pop();	//스택에서 이전에 실행한 Activity의 이름을 가져옴
		System.out.println("(pop) " + panelName);
		getContentPane().removeAll();			//컨테이너의 모든 컴포넌트 제거
		switch(panelName) {
			case "LoginActivity" : 			getContentPane().add(LoginActivity);			break;
			case "RegistrationActivity" : 	getContentPane().add(RegistrationActivity);		break;
			case "AuthorizationActivity" : 	getContentPane().add(AuthorizationActivity);	break;
			case "WritingActivity" : 		getContentPane().add(WritingActivity);			break;
			case "ReadingActivity" : 		getContentPane().add(ReadingActivity);			break;
			case "MainActivity" : 			getContentPane().add(MainActivity);				break;
		}
		revalidate();							//배치관리자가 컴포넌트들을 다시 배치하도록 함
		repaint();								//컨테이너를 다시 그림
	}
}