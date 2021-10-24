import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

//읽기 전용 게시판의 화면을 구성하는 액티비티
public class ReadingActivity extends JPanel {
	private JLabel IDLabel;
	private JTextArea BulletinBoard;
	private JLabel filenameLabel;
	private String filename = "";
	private JScrollPane scrollPane;
	
	public ReadingActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//게시판 레이블
		JLabel BB = new JLabel("읽기 전용 게시판");
		BB.setFont(new Font("맑은 고딕", Font.PLAIN, 28));
		BB.setBounds(420, 25, 350, 50);
		add(BB);
		
		//텍스트 파일의 이름이 담긴 레이블
		filenameLabel = new JLabel();
		filenameLabel.setFont(new Font("맑은 고딕", Font.BOLD, 20));
		filenameLabel.setBounds(660, 35, 200, 30);
		add(filenameLabel);
		
		//읽어온 텍스트를 보여주는 게시판 텍스트공간
		BulletinBoard = new JTextArea();
		BulletinBoard.setFont(new Font("맑은 고딕", Font.PLAIN, 20));
		BulletinBoard.setEnabled(false);
		scrollPane = new JScrollPane(BulletinBoard);
		scrollPane.setBounds(200, 90, 800, 490);
		add(scrollPane);
		
		//로그인한  id 및 권한 출력 레이블
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
				BulletinBoard.setText("");	//게시판 내용 초기화
				win.goback();
			}
		});
	}
	
	//외부에서 호출할 수 있도록 public으로 선언
	public void init() {
		setInfoLabel();		//화면에 로그인 한 사람의 정보(ID, 권한) 출력
		setFilename();		//파일제목 라벨에 파일이름 출력
		loadText();			//게시판의 내용(txt파일)을 읽어 텍스트 에어리어에 출력
	}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>내 계정 정보<br><BR/>" + "ID : " + Login.id + "<br/>" + "Level : " + Login.authority + "</html>");
	}
	
	private void setFilename() {
		filenameLabel.setText("ㅡ   " + MainActivity.filename);
	}
	
	//텍스트를 불러와 읽고, 이를 게시판 텍스트공간에 출력함
	private void loadText() {
		String line;
		
		try {
			filename = MainActivity.filename + ".txt";
			File fin = new File("BulletinBoard", filename);
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(fin),"UTF-8"));	//한글을 읽기 위해 "UTF-8"로 인코딩
			
			while((line = br.readLine()) != null)
				BulletinBoard.append(line + "\n");
			BulletinBoard.setCaretPosition(0);		//파일을 덧붙이는 작업이 끝난 후 삽입기호의 위치를 0으로 변경(스크롤페인을 가장 위로 올림)
			br.close();								//스트림 닫음
		}
		catch (FileNotFoundException e) {			//파일을 찾지 못한 오류
			JOptionPane.showMessageDialog(null, MainActivity.filename + "파일 없음", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException e) {						//파일 IO 오류
			JOptionPane.showMessageDialog(null, "입출력 오류", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
}
