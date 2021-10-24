import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

//권한 설정하는 화면을 구성하는 액티비티
class AuthorizationActivity extends JPanel {
	private JLabel IDLabel;
	private String [] Level = {"레벨", "1", "2", "3", "4", "5", "6"};
	private String targetID = "";		//권한이 적용될 대상 ID
	private int targetLevel;			//적용할 권한 값
	private JComboBox<String> IDCombo = new JComboBox<String>();
	private JComboBox<String> LevelCombo = new JComboBox<String>(Level);

	public AuthorizationActivity (MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		JLabel title = new JLabel("권한 설정");
		title.setFont(new Font("맑은 고딕", Font.PLAIN, 35));
		title.setBounds(480, 80, 400, 100);
		add(title);
		
		//권한 설정할 아이디를 선택할 수 있는 ID콤보박스
		IDCombo.setBounds(420, 250, 100, 30);
		IDCombo.setBackground(new Color(237, 247, 245));
		IDCombo.setForeground(new Color(32, 78, 95));
		add(IDCombo);
		IDCombo.addItemListener(new ItemListener() {
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == ItemEvent.SELECTED) {
					JComboBox<String> IDCombo = (JComboBox<String>)e.getSource();
					targetID = (String) IDCombo.getSelectedItem();
				}
			}
		});
		
		//권한을 선택할 수 있는 Level콤보박스
		LevelCombo.setBounds(523, 250, 100, 30);
		LevelCombo.setBackground(new Color(237, 247, 245));
		LevelCombo.setForeground(new Color(32, 78, 95));
		add(LevelCombo);
		LevelCombo.addItemListener(new ItemListener() {
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == ItemEvent.SELECTED) {
					JComboBox<Integer> LevelCombo = (JComboBox<Integer>)e.getSource();
					targetLevel = LevelCombo.getSelectedIndex();
				}
			}
		});
		
		//로그아웃 버튼
		JButton LogoutButton = new JButton("로그아웃");
		LogoutButton.setBounds(170, 40, 100, 20);
		LogoutButton.setBackground(new Color(237, 247, 245));
		add(LogoutButton);
		LogoutButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				IDCombo.removeAllItems();
				win.logout();
			}
		});
		
		//계정 정보 레이블
		IDLabel = new JLabel();
		IDLabel.setFont(new Font("맑은 고딕", Font.BOLD, 15));
		IDLabel.setBounds(30, 30, 100, 80);
		add(IDLabel);
		
		//권한 적용 버튼
		JButton ApplyButton = new JButton("적용하기");
		ApplyButton.setBounds(643, 255, 90, 20);
		ApplyButton.setBackground(new Color(255, 198, 168));
		add(ApplyButton);
		//권한 적용 시도 이후 일어나는 액션
		ApplyButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					//콤보박스의 가장 위 항목을 제외하고 선택한 경우
					if((targetID != null) && (!targetID.equals("아이디") && (targetLevel != 0))) {
						System.out.println("============================");
						File info = new File("MemberInfo.txt");									//회원정보가 있는 파일 경로
						File temp = new File("temp.txt");										//변경된 권한을 덮어 쓰기 위한 임시 파일
						//계정 정보 파일에서 읽어와 임시 파일에 작성하는 버퍼 생성
						BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(info), "UTF-8"));				//한글을 읽기 위해 "UTF-8"로 인코딩
						BufferedWriter bw = new BufferedWriter(new FileWriter(temp));
						
						String currentLine;
						while((currentLine = br.readLine()) != null){
							//일치하는 아이디를 찾은 경우 권한 수정 됨
							if(currentLine.contains(targetID)) {								// 수정할 ID를 찾은 경우
								String tokens[] = currentLine.split("\t");
								if(targetID.equals(tokens[0])) {								//txt파일의 ID값인 tokens[0]과 콤보박스의 targetID가 일치하는지 비교
									bw.write(tokens[0] + "\t" + tokens[1] + "\t" + targetLevel + System.getProperty("line.separator"));	//변경된 회원정보 저장
									System.out.println("renewLine | " + tokens[0] + "\t" + tokens[1] + "\t" + targetLevel);
								}
							}
							//일치하는 아이디를 찾지 못한 경우
							else {	
								bw.write(currentLine + System.getProperty("line.separator"));	//읽은 라인을 행 구분문자(line.separator)를 적용하기 위해 getProperty메소드 사용하여 작성
								System.out.println(" keepLine | " + currentLine);
							}
						}
						System.out.println("============================");
						bw.close();			
						br.close();					
						info.delete();						//기존 파일 삭제 후,
						temp.renameTo(info);				//새로 작성한 임시파일의 이름을 기존의 파일이름으로 변경
						JOptionPane.showMessageDialog(null, "적용 완료", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);	
					}
					//콤보박스를 선택하지 않았거나, 콤보박스의 가장 위 항목을 선택한 경우
					else
						JOptionPane.showMessageDialog(null, "콤보박스 선택안됨", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
				catch (FileNotFoundException exc) {			//파일을 찾지 못한 오류
					JOptionPane.showMessageDialog(null, "파일을 열 수 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (IOException exc) {					//파일 IO 오류
					JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
			}
		});
	}
	
	//외부에서 호출할 수 있도록 public으로 선언
	public void init() {
		addName();									//MemberInfo.txt파일에서 ID를 가져와 IDComboBox에 추가
		setInfoLabel();								//화면에 로그인 한 관리자의 정보(ID) 출력
	}
	
	//MemberInfo.txt파일에서 ID를 가져와 IDComboBox에 추가하는 메소드
	private void addName() {
		String STR;										//MemberInfo.txt에서 한 줄씩 읽기 위해 String형 변수 STR 선언
		
		try {
			File file = new File("MemberInfo.txt");
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file), "UTF-8"));	//한글을 읽기 위해 "UTF-8"로 인코딩
			
			IDCombo.addItem("아이디");
			while((STR = br.readLine()) != null) {
				IDCombo.addItem(STR.split("\t")[0]);	//토큰 자름 - 0번 : 아이디 1번 : 비밀번호, 2번 : 권한
			}
			br.close();									//스트림 닫음
		}
		catch (FileNotFoundException exce) {			//파일을 찾지 못한 오류
			JOptionPane.showMessageDialog(null, "회원정보 파일 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException exce) {						//파일 IO 오류
			JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>내 계정 정보<br><BR/>" + "ID : " + Login.id + "</html>");
	}
}