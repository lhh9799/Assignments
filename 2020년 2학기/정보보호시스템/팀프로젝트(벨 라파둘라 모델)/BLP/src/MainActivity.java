import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.io.File;

//로그인 이후, 파일 선택 및 작업 선택 화면을 구성하는 액티비티
public class MainActivity extends JPanel {
	private JLabel IDLabel;
	private String [] actions = {"작업 선택", "쓰기", "읽기"};
	private JComboBox<String> typeCombo = new JComboBox<String>();
	private JComboBox<String> actionCombo = new JComboBox<String>(actions);
	private boolean eventFlag = true;		//itemStateChanged의 작동을 일시중지하기 위한 장치
	static String filename;
	private int target1, target2;
	
	public MainActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//액티비티 타이틀 레이블
		JLabel title = new JLabel("파일 및 작업 선택");
		title.setFont(new Font("맑은 고딕", Font.PLAIN, 35));
		title.setBounds(420, 80, 400, 100);
		add(title);
		
		//로그인한  id 및 권한 출력 레이블
		IDLabel = new JLabel();
		IDLabel.setFont(new Font("맑은 고딕", Font.BOLD, 15));
		IDLabel.setBounds(30, 30, 100, 80);
		add(IDLabel);
		
		//로그아웃 버튼
		JButton LogoutButton = new JButton("로그아웃");
		LogoutButton.setFont(new Font("맑은 고딕", Font.BOLD, 11));
		LogoutButton.setBounds(170, 31, 100, 20);
		LogoutButton.setBackground(new Color(237, 247, 245));
		add(LogoutButton);
		LogoutButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				win.logout();
			}
		});
				
		//게시판 이름을 선택하는 type콤보박스
		typeCombo.setBounds(400, 250, 100, 30);
		typeCombo.setBackground(new Color(237, 247, 245));
		typeCombo.setForeground(new Color(32, 78, 95));
		add(typeCombo);
		typeCombo.addItemListener(new ItemListener() {
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == ItemEvent.SELECTED && eventFlag == true) {
//				if(e.getStateChange() == ItemEvent.SELECTED) {
					JComboBox<String> choice = (JComboBox<String>)e.getSource();
					filename = (String) choice.getSelectedItem();
					target1 = Character.getNumericValue(filename.charAt(3));	//선택된 파일의 이름에서 레벨을 가져옴
				}
			}
		});
		
		//작업을 선택하는 action콤보박스
		actionCombo.setBounds(503, 250, 100, 30);
		actionCombo.setBackground(new Color(237, 247, 245));
		actionCombo.setForeground(new Color(32, 78, 95));
		add(actionCombo);
		actionCombo.addItemListener(new ItemListener() {
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == ItemEvent.SELECTED && eventFlag == true) {
					JComboBox<String> choice = (JComboBox<String>)e.getSource();
					target2 = choice.getSelectedIndex();
				}
			}
		});
		
		//게시판 및 작업을 선택한 후 다음 액티비티로 넘어가기 위한 확인 버튼
		JButton ConfirmButton = new JButton("확인");
		LogoutButton.setFont(new Font("맑은 고딕", Font.BOLD, 11));
		ConfirmButton.setBounds(623, 255, 80, 20);
		ConfirmButton.setBackground(new Color(255, 198, 168));
		add(ConfirmButton);
		ConfirmButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//콤보박스를 선택하지 않은 경우
				if(target1 != 0 && target2 != 0) {
//					filename += ".txt";
					switch(target2) {
					//콤보박스에서 쓰기를 선택한 경우
					case 1	:
						if(Login.authority > target1) {								//회원의 레벨이 게시판의 레벨보다 숫자가 큰 경우 즉,작성 가능한 경우
							JOptionPane.showMessageDialog(null, "파일이 이미 있습니다.\n파일 이름을 변경하세요.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
							win.change("WritingActivity", "MainActivity");
							break;
						}
						//회원의 레벨이 게시판의 레벨보다 숫자가 작은 경우 즉,작성 불가능한 경우
						else {	
							JOptionPane.showMessageDialog(null, "쓰기가 불가능한 계정입니다.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
							break;
						}
					//콤보박스에서 읽기를 선택한 경우
					case 2 :
						if(Login.authority < target1) {								//회원의 레벨이 게시판의 레벨보다 숫자가 작은 경우 즉, 읽기 가능한 경우
							win.change("ReadingActivity", "MainActivity");
							break;
							}
						
						else {														//회원의 레벨이 게시판의 레벨보다 숫자가 작은 경우 즉, 읽기 불가능한 경우
							JOptionPane.showMessageDialog(null, "읽기가 불가능한 계정입니다.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
							break;
						}
					}
				}
				//콤보박스가 선택되지 않은 경우
				else {
					JOptionPane.showMessageDialog(null, "콤보박스 선택안됨", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
			}
		});
	}
	
	//콤보박스에서 선택한 파일의 이름이 이미 존재하는지 확인하는 메소드. 존재하면 true, 존재하지 않으면 false 리턴
	public static boolean doesfilealreadyexist(String filename) {
		File file;
		File dir = new File("BulletinBoard");
		File[] fileList = dir.listFiles();
		for(int i=0; i<fileList.length; i++) {
			file = fileList[i];
			
			if(file.getName().equals(filename))
				return true;
		}
		return false;
	}
	
	//외부에서 호출할 수 있도록 public으로 선언
	public void init() {
		typeCombo.removeAllItems();	//이후 MainActivity가 다시 호출되었을 때 새로운 파일 리스트를 나열하기 위해 콤보박스 초기화
		addFileName();				//콤보박스에 파일 리스트를 추가
		setInfoLabel();				//화면에 로그인 한 사람의 정보(ID, 권한) 출력
	}
	
	//파일 목록을 읽어와 파일 선택 콤보박스(typeCombe)에 넣는 메소드
		private void addFileName() {
			File dir = new File("BulletinBoard");
			File[] fileList = dir.listFiles();
				
			typeCombo.addItem("파일 선택");
			for(int i=0; i<fileList.length; i++) {
				String file = fileList[i].getName();
				typeCombo.addItem(file.split("\\.")[0]);
			}
		}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>내 계정 정보<br><BR/>" + "ID : " + Login.id + "<br/>" + "Level : " + Login.authority + "</html>");
	}
}
