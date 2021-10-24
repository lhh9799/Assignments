import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

//회원가입 화면을 구성하는 액티비티
public class RegistrationActivity extends JPanel {
	private boolean check = false;		//중복확인 여부를 판단하는 변수
	private JTextField ID;
	private JPasswordField PW;
	private Registration r = new Registration();
	
	public RegistrationActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//액티비티 타이틀 레이블
		JLabel title = new JLabel("회원가입");
		title.setFont(new Font("맑은 고딕", Font.PLAIN, 35));
		title.setBounds(480, 80, 400, 100);
		add(title);
		
		//아이디 레이블
		JLabel IDLabel = new JLabel("ID");
		IDLabel.setBounds(400, 250, 67, 15);
		add(IDLabel);
		//아이디 텍스트필드
		ID = new JTextField();
		ID.setBounds(485, 250, 116, 21);
		add(ID);
		ID.setColumns(12);
		
		//비밀번호 레이블
		JLabel PWLabel = new JLabel("password");
		PWLabel.setBounds(400, 280, 67, 15);
		add(PWLabel);
		//비밀번호 패스워드 필드
		PW = new JPasswordField(15);
		PW.setBounds(485, 280, 116, 21);
		add(PW);
		
		//뒤로가기 버튼
		JButton BackButton = new JButton("뒤로가기");
		BackButton.setBounds(50, 560, 100, 20);
		BackButton.setBackground(new Color(237, 247, 245));
		add(BackButton);
		BackButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ID.setText("");	PW.setText("");
				win.goback();
			}
		});
		
		//생성하기 버튼
		JButton RegistrationButton = new JButton("생성하기");
		RegistrationButton.setFont(new Font("맑은 고딕", Font.BOLD, 13));
		RegistrationButton.setSize(90, 40);
		RegistrationButton.setLocation(628, 320);
		RegistrationButton.setBackground(new Color(255, 137, 132));
		add(RegistrationButton);
		RegistrationButton.addActionListener(new ActionListener() {
			@Override
			//생성을 시도한 경우
			public void actionPerformed(ActionEvent e) {
				//아이디 생성이 가능한 경우(공백 X, 중복 X, 중복확인 완료)
				if((!ID.getText().equals("")) && (!PW.getText().equals("")) && (r.redundancyCheck(ID.getText()) == false) && check == true) {
					check = false;
					r.register(ID.getText(), PW.getText());
					JOptionPane.showMessageDialog(null, "생성 완료", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
				//아이디 생성이 불가능한 경우
				else if(check == false)
					JOptionPane.showMessageDialog(null, "중복확인이 완료되지 않았습니다.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else if(ID.getText().equals(""))
					JOptionPane.showMessageDialog(null, "아이디가 공란입니다.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else if(PW.getText().equals(""))
					JOptionPane.showMessageDialog(null, "비밀번호가 공란입니다.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else
					JOptionPane.showMessageDialog(null, "아이디 중복", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			}
		});
		
		//중복확인 버튼
		JButton redundancyCheck = new JButton("중복확인");
		redundancyCheck.setFont(new Font("맑은 고딕", Font.BOLD, 11));
		redundancyCheck.setSize(90, 20);
		redundancyCheck.setLocation(630, 250);
		redundancyCheck.setBackground(new Color(255, 198, 168));
		add(redundancyCheck);
		redundancyCheck.addActionListener(new ActionListener() {
			@Override
			//ID 중복확인을 시도한 경우
			public void actionPerformed(ActionEvent e) {
				//중복확인 실패 시 (가입 시도한 아이디가 공백이거나 중복인 경우)
				if(ID.getText().equals("") || ID.getText().equals("admin"))
					JOptionPane.showMessageDialog(null, "아이디를 다시 입력하세요", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else if(r.redundancyCheck(ID.getText()) == true)
					JOptionPane.showMessageDialog(null, "아이디 중복", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				//중복확인 성공 시
				else {
					check = true;
					JOptionPane.showMessageDialog(null, "사용 가능한 아이디", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
			}
		});
	}
}