import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

//로그인하는 화면을 구성하는 액티비티
class LoginActivity extends JPanel {
	private MyJPanel win;
	private JTextField ID;
	private JPasswordField PW;
	private Login login;
	
	public LoginActivity(MyJPanel win) {
		this.win = win;		//main함수의 MyJPanel형 변수 win을 LoginActivity객체의 MyJPanel형 변수 win에 저장 -> 이후 win.change 메소드를 사용하기 위함
		setLayout(null);
		login = new Login();
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.DARK_GRAY, 5), "="));
		
		//타이틀 레이블
		JLabel title = new JLabel("벨 라파둘라 프로그램");
		title.setFont(new Font("맑은 고딕", Font.PLAIN, 35));
		title.setBounds(390, 15, 400, 100);
		add(title);
		
		//설명 패널
		JPanel inst = new JPanel();
		inst.setLayout(null);
		inst.setBounds(60, 110, 960, 300);
		inst.setBackground(new Color(150, 190, 190));
		inst.setBorder(new LineBorder(Color.LIGHT_GRAY, 2));
		//설명 패널에 추가할 이미지
		Image image = new ImageIcon("bellimage.jpg").getImage();
		Image chimage = image.getScaledInstance(800, 150, Image.SCALE_SMOOTH);
		JLabel imageLabel = new JLabel(new ImageIcon(chimage));
		imageLabel.setBounds(90, 15, 800, 150);
		//설명 패널에 추가할 글
		JLabel instLabel = new JLabel("<html>벨 라파둘라 모델은 최초의 수학적 모델로 강제적 정책에 의해 접근 통제하는 모델로써, 보안 정책은 정보가 높은 레벨에서 낮은 레벨로 흐르는 것을 방지합니다. 군대의 보안 레벨과 같이 정보의 기밀성에 따라 상하 관계가 구분된 정보를 보호하기 위해 사용합니다. <br> bell-lapadula 모델의 접근통제 규칙은 no read up, no write down로, 낮은 등급의 소유자는 높은 등급의 문서를 읽을 수 없고 높은 등급의 소유자는 낮은 등급의 문서를 수정할 수 없습니다.<html/>");
		instLabel.setFont(new Font("나눔바른고딕", Font.PLAIN, 15));
		instLabel.setBounds(20, 155, 900, 150);
		inst.add(instLabel);
		inst.add(imageLabel);		
		add(inst);
		
		//아이디 레이블
		JLabel IDLabel = new JLabel("ID");
		IDLabel.setBounds(400, 440, 80, 20);
		add(IDLabel);
		
		//아이디 텍스트필드
		ID = new JTextField();
		ID.setBounds(490, 440, 116, 21);
		ID.setColumns(12);
		add(ID);
		//아이디 텍스트필드로 포커싱
		ID.requestFocus();
		win.addWindowListener(new WindowAdapter() { 
			public void windowOpened( WindowEvent e ) { 
				ID.requestFocus(); 
			} 
		});
		
		//비밀번호 레이블
		JLabel PWLabel = new JLabel("password");
		PWLabel.setBounds(400, 470, 80, 20);
		add(PWLabel);
		
		//비밀번호 패스워드필드
		PW = new JPasswordField();
		PW.setBounds(490, 470, 116, 21);
		PW.addActionListener(new MyActionListener());
		add(PW);
		
		//로그인 버튼
		JButton LoginButton = new JButton("로그인");
		LoginButton.setFont(new Font("맑은 고딕", Font.BOLD, 13));
		LoginButton.setSize(80, 40);
		LoginButton.setLocation(625, 450);
		LoginButton.setBackground(new Color(255, 137, 132));
		LoginButton.addActionListener(new MyActionListener());
		add(LoginButton);
		
		//회원가입 레이블
		JLabel RegisterLabel = new JLabel("회원이 아니신가요?");
		RegisterLabel.setFont(new Font("맑은 고딕", Font.BOLD, 12));
		RegisterLabel.setBounds(420, 530, 150, 20);
		add(RegisterLabel);
		
		//회원가입 버튼
		JButton RegisterButton = new JButton("회원가입");
		RegisterButton.setFont(new Font("맑은 고딕", Font.BOLD, 11));
		RegisterButton.setSize(100, 23);
		RegisterButton.setLocation(570, 529);
		RegisterButton.setBackground(new Color(237, 247, 245));
		add(RegisterButton);
		RegisterButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				setTextfieldClear();
				win.change("RegistrationActivity", "LoginActivity");
			}
		});
		
//		//탭 순서 지정 - deprecated
//		ID.setNextFocusableComponent(PW);
//		PW.setNextFocusableComponent(LoginButton);
	}
	
	//로그인 시도 이후 일어나는 액션
	class MyActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			//일반 계정으로 로그인 성공 시
			if(login.verify(ID.getText(), PW.getText())) {
				win.change("MainActivity", "LoginActivity");
				setTextfieldClear();
				System.out.println("로그인 성공 ID = " + Login.id + ", authority = " + Login.authority);
			}
			//admin 계정으로 로그인 성공 시
			else if((ID.getText().equals("admin")) && PW.getText().equals("admin")) {
				login.id = "admin";
				setTextfieldClear();
				win.change("AuthorizationActivity", "LoginActivity");
			}
			//로그인 실패 시
			else if((ID.getText().equals("") && PW.getText().equals("")))
				JOptionPane.showMessageDialog(null, "아이디, 비밀번호를 입력하세요", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			else if((ID.getText().equals("")))
				JOptionPane.showMessageDialog(null, "아이디를 입력하세요", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			else if((PW.getText().equals("")))
				JOptionPane.showMessageDialog(null, "비밀번호를 입력하세요", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			else
				JOptionPane.showMessageDialog(null, "회원정보 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	private void setTextfieldClear() {
		ID.setText("");
		PW.setText("");
	}
}