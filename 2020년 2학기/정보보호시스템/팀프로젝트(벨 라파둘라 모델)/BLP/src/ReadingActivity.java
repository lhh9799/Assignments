import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

//�б� ���� �Խ����� ȭ���� �����ϴ� ��Ƽ��Ƽ
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
		
		//�Խ��� ���̺�
		JLabel BB = new JLabel("�б� ���� �Խ���");
		BB.setFont(new Font("���� ���", Font.PLAIN, 28));
		BB.setBounds(420, 25, 350, 50);
		add(BB);
		
		//�ؽ�Ʈ ������ �̸��� ��� ���̺�
		filenameLabel = new JLabel();
		filenameLabel.setFont(new Font("���� ���", Font.BOLD, 20));
		filenameLabel.setBounds(660, 35, 200, 30);
		add(filenameLabel);
		
		//�о�� �ؽ�Ʈ�� �����ִ� �Խ��� �ؽ�Ʈ����
		BulletinBoard = new JTextArea();
		BulletinBoard.setFont(new Font("���� ���", Font.PLAIN, 20));
		BulletinBoard.setEnabled(false);
		scrollPane = new JScrollPane(BulletinBoard);
		scrollPane.setBounds(200, 90, 800, 490);
		add(scrollPane);
		
		//�α�����  id �� ���� ��� ���̺�
		IDLabel = new JLabel();
		IDLabel.setFont(new Font("���� ���", Font.BOLD, 15));
		IDLabel.setBounds(30, 30, 100, 80);
		add(IDLabel);
				
		//�ڷΰ��� ��ư
		JButton BackButton = new JButton("�ڷΰ���");
		BackButton.setBounds(50, 560, 100, 20);
		BackButton.setBackground(new Color(237, 247, 245));
		add(BackButton);
		BackButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BulletinBoard.setText("");	//�Խ��� ���� �ʱ�ȭ
				win.goback();
			}
		});
	}
	
	//�ܺο��� ȣ���� �� �ֵ��� public���� ����
	public void init() {
		setInfoLabel();		//ȭ�鿡 �α��� �� ����� ����(ID, ����) ���
		setFilename();		//�������� �󺧿� �����̸� ���
		loadText();			//�Խ����� ����(txt����)�� �о� �ؽ�Ʈ ���� ���
	}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>�� ���� ����<br><BR/>" + "ID : " + Login.id + "<br/>" + "Level : " + Login.authority + "</html>");
	}
	
	private void setFilename() {
		filenameLabel.setText("��   " + MainActivity.filename);
	}
	
	//�ؽ�Ʈ�� �ҷ��� �а�, �̸� �Խ��� �ؽ�Ʈ������ �����
	private void loadText() {
		String line;
		
		try {
			filename = MainActivity.filename + ".txt";
			File fin = new File("BulletinBoard", filename);
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(fin),"UTF-8"));	//�ѱ��� �б� ���� "UTF-8"�� ���ڵ�
			
			while((line = br.readLine()) != null)
				BulletinBoard.append(line + "\n");
			BulletinBoard.setCaretPosition(0);		//������ �����̴� �۾��� ���� �� ���Ա�ȣ�� ��ġ�� 0���� ����(��ũ�������� ���� ���� �ø�)
			br.close();								//��Ʈ�� ����
		}
		catch (FileNotFoundException e) {			//������ ã�� ���� ����
			JOptionPane.showMessageDialog(null, MainActivity.filename + "���� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException e) {						//���� IO ����
			JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
}
