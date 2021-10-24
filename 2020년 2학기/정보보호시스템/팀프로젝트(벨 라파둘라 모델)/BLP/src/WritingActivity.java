import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.awt.Color;
import java.awt.Font;

//쓰기 전용 게시판의 화면을 구성하는 액티비티
public class WritingActivity extends JPanel {
	private JLabel IDLabel;
	private String [] Variation = {"선택", "_1", "_2", "_3", "_4", "_5", "_6"};
	private JTextArea BulletinBoard;
	private JLabel filenameLabel;
	private String filename = "";
	private boolean eventFlag = true;												//itemStateChanged의 작동을 일시중지하기 위한 장치
	private JComboBox<String> VariationCombo = new JComboBox<String>(Variation);	//이전 Activity에서 파일 이름이 중복인 경우 기존의 파일 이름에 덧붙일 수 있도록 하는 콤보박스
	
	public WritingActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//로그인한  id 및 권한 출력하는 레이블
		IDLabel = new JLabel();
		IDLabel.setFont(new Font("맑은 고딕", Font.BOLD, 15));
		IDLabel.setBounds(30, 30, 100, 80);
		add(IDLabel);
		
		//뒤로가기 버튼
		JButton BackButton = new JButton("뒤로가기");
		BackButton.setBounds(50, 560, 100, 20);
		BackButton.setBackground(new Color(237, 247, 245));
		add(BackButton);
		BackButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				initCombo();
				win.goback();
			}
		});
		
		//저장할 문서 타이틀에 덧붙일 문자를 선택하는 Variation콤보박스
		VariationCombo.setBounds(50, 150, 100, 30);
		VariationCombo.setBackground(new Color(237, 247, 245));
		VariationCombo.setForeground(new Color(32, 78, 95));
		VariationCombo.addItemListener(new ItemListener() {
			@Override
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == ItemEvent.SELECTED && eventFlag == true) {
					JComboBox<String> VariationCombo = (JComboBox<String>)e.getSource();
					if(VariationCombo.getSelectedIndex() != 0) {
						String choice = (String) VariationCombo.getSelectedItem();
						filename = MainActivity.filename + choice + ".txt";
					}
				}
				else	//콤보박스의 상태가 "선택"인 경우
					filename = MainActivity.filename + ".txt";
				setFilename();
			}
		});
		add(VariationCombo);
		
		//게시판 타이틀 레이블
		JLabel BB = new JLabel("쓰기 전용 게시판");
		BB.setFont(new Font("맑은 고딕", Font.PLAIN, 28));
		BB.setBounds(420, 25, 350, 50);
		add(BB);
		
		//게시판의 이름을 보여주는 레이블
		filenameLabel = new JLabel();
		filenameLabel.setFont(new Font("맑은 고딕", Font.BOLD, 20));
		filenameLabel.setBounds(660, 35, 200, 30);
		add(filenameLabel);
		
		//게시판 텍스트공간 - 저장할 문서의 내용을 사용자가 작성하는 곳
		BulletinBoard = new JTextArea();
		BulletinBoard.setFont(new Font("맑은 고딕", Font.PLAIN, 20));
		BulletinBoard.setEnabled(true);
		JScrollPane scrollPane = new JScrollPane(BulletinBoard);
		scrollPane.setBounds(200, 90, 800, 490);
		add(scrollPane);
		
		//저장하기 버튼 - 버튼을 누르면 저장할 파일명이 결정되고, 파일명의 중복 여부를 판단하여 파일을 저장함
		JButton saveButton = new JButton("저장하기");
		saveButton.setBounds(50, 500, 100, 30);
		saveButton.setBackground(new Color(255, 137, 132));
		add(saveButton);
		saveButton.addActionListener(new ActionListener() {
			@Override
			//파일을 저장하려고 시도한 경우
			public void actionPerformed(ActionEvent e) {
				try {
					//파일명이 중복이 아닌 경우
					if(!MainActivity.doesfilealreadyexist(filename)) {				
						File newFile = new File("BulletinBoard", filename);
						BufferedWriter bw = new BufferedWriter(new FileWriter(newFile, false));			//false : 파일이 이미 존재하는 경우 파일을 덮어씀
						PrintWriter pw = new PrintWriter(bw, true);										//true : 생성된 파일의 뒤에 이어서 씀
						pw.write(BulletinBoard.getText());												//JTextArea에서 내용을 가져와 pw객체를 통해 텍스트파일에 작성
						bw.close();
						pw.close();	
						JOptionPane.showMessageDialog(null, "저장 완료", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
						//상위레벨에 쓰기는 가능하나, 읽기는 불가능하므로 저장버튼을 누르고 1초 뒤 메인화면으로 돌아간다.
						Thread.sleep(1000);			//스레드 일시중지 1000ms(=1s)
						BulletinBoard.setText("");	//게시판 내용 초기화
						initCombo();				//콤보박스 선택 초기화
						win.MainActivity.init();	//MainActivity의 콤보박스의 리스트를 갱신하기 위함
						win.goback();				//뒤로 돌아간다.
					}
					//파일명이 중복인 경우
					else
						JOptionPane.showMessageDialog(null, "파일이름 중복", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (FileNotFoundException exc) {			//파일을 찾지 못한 오류
					JOptionPane.showMessageDialog(null, "파일을 열 수 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (IOException exc) {					//파일 IO 오류
					JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (InterruptedException exc) {			//스레드가 중단되었을 때 발생하는 오류. 대기중인 스레드가 깨어나지 못할 때 발생
					System.out.println(exc.getMessage());
				}
			}
		});
	}
	
	private void initCombo() {
		eventFlag = false;	//itemStateChanged가 작동하지 않기 위해 eventFlag의 값을 false로 변경
		VariationCombo.setSelectedIndex(0);
		eventFlag = true;	//itemStateChanged가 다시 작동하도록 하기 위해 eventFlag의 값을 true로 변경
	}
	
	//외부에서 호출할 수 있도록 public으로 선언
	public void init() {
		filename = MainActivity.filename + ".txt";
		setInfoLabel();				//화면에 로그인 한 사람의 정보(ID, 권한) 출력
		setFilename();				//화면에 콤보박스에서 선택한 아이템을 반영한 파일제목을 출력
	}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>내 계정 정보<br><BR/>" + "ID : " + Login.id + "<br/>" + "Level : " + Login.authority + "</html>");
	}
	
	private void setFilename() {
		filenameLabel.setText("ㅡ   " + filename);
	}
}
