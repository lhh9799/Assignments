import javax.swing.*;
import java.util.Stack;

//��Ű���� ��� Activity���� �����ϱ� ���� Ŭ����
class MyJPanel extends JFrame {
	private Stack<String> ActivityStack = new Stack<>();	//����� ȭ���� ������ ����ϱ� ���� ����
	
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
	
	//ȭ���� ��ȯ�����ִ� �޼ҵ�
	public void change(String panelName, String caller) {
		ActivityStack.push(caller);				//change �޼ҵ带 �θ� ��Ƽ��Ƽ�� �̸��� ���ÿ� ����
		System.out.println("(push) " + panelName);
		getContentPane().removeAll();			//�����̳��� ��� ������Ʈ ����
		switch(panelName) {
		//���α׷��� �����ϸ� ��� Activity���� �� �� �� �����Ҵ� �Ǳ� ������(�� Activity���� ���� �ϱ� ������) �߰����� ������ �ʿ��� Activity���� init()�޼ҵ带 ������ �ִ�. 
			case "LoginActivity" : 											getContentPane().add(LoginActivity);			break;
			case "RegistrationActivity" : 									getContentPane().add(RegistrationActivity);		break;
			case "MainActivity" : 			MainActivity.init();			getContentPane().add(MainActivity);				break;
			case "AuthorizationActivity" : 	AuthorizationActivity.init();	getContentPane().add(AuthorizationActivity);	break;
			case "WritingActivity" : 		WritingActivity.init();			getContentPane().add(WritingActivity);			break;
			case "ReadingActivity" : 		ReadingActivity.init(); 		getContentPane().add(ReadingActivity);			break;
		}
		revalidate();							//��ġ�����ڰ� ������Ʈ���� �ٽ� ��ġ�ϵ��� ��
		repaint();								//�����̳ʸ� �ٽ� �׸�
	}	
	
	//�α׾ƿ� �޼ҵ�
	public void logout() {
		Login.authority = 0;					//�α����� ������ ������ 0���� �ʱ�ȭ
		getContentPane().removeAll();		getContentPane().add(LoginActivity);	revalidate();	repaint();
		ActivityStack.clear();					//���� �ʱ�ȭ
		System.out.println("(clear) ActivityStack");
	}
	
	//���� ȭ������ �ǵ��ư��� �޼ҵ� (�ڷΰ��� ����� ��). �ڷΰ����� ��� �α��������� �ٲ��� �ʾ����Ƿ� ������ �ٽ� ������ �� �ʿ䰡 ����.
	public void goback() {
		String panelName = ActivityStack.pop();	//���ÿ��� ������ ������ Activity�� �̸��� ������
		System.out.println("(pop) " + panelName);
		getContentPane().removeAll();			//�����̳��� ��� ������Ʈ ����
		switch(panelName) {
			case "LoginActivity" : 			getContentPane().add(LoginActivity);			break;
			case "RegistrationActivity" : 	getContentPane().add(RegistrationActivity);		break;
			case "AuthorizationActivity" : 	getContentPane().add(AuthorizationActivity);	break;
			case "WritingActivity" : 		getContentPane().add(WritingActivity);			break;
			case "ReadingActivity" : 		getContentPane().add(ReadingActivity);			break;
			case "MainActivity" : 			getContentPane().add(MainActivity);				break;
		}
		revalidate();							//��ġ�����ڰ� ������Ʈ���� �ٽ� ��ġ�ϵ��� ��
		repaint();								//�����̳ʸ� �ٽ� �׸�
	}
}