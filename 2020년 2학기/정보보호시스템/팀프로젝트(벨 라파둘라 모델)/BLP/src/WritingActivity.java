import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.awt.Color;
import java.awt.Font;

//���� ���� �Խ����� ȭ���� �����ϴ� ��Ƽ��Ƽ
public class WritingActivity extends JPanel {
	private JLabel IDLabel;
	private String [] Variation = {"����", "_1", "_2", "_3", "_4", "_5", "_6"};
	private JTextArea BulletinBoard;
	private JLabel filenameLabel;
	private String filename = "";
	private boolean eventFlag = true;												//itemStateChanged�� �۵��� �Ͻ������ϱ� ���� ��ġ
	private JComboBox<String> VariationCombo = new JComboBox<String>(Variation);	//���� Activity���� ���� �̸��� �ߺ��� ��� ������ ���� �̸��� ������ �� �ֵ��� �ϴ� �޺��ڽ�
	
	public WritingActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//�α�����  id �� ���� ����ϴ� ���̺�
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
				initCombo();
				win.goback();
			}
		});
		
		//������ ���� Ÿ��Ʋ�� ������ ���ڸ� �����ϴ� Variation�޺��ڽ�
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
				else	//�޺��ڽ��� ���°� "����"�� ���
					filename = MainActivity.filename + ".txt";
				setFilename();
			}
		});
		add(VariationCombo);
		
		//�Խ��� Ÿ��Ʋ ���̺�
		JLabel BB = new JLabel("���� ���� �Խ���");
		BB.setFont(new Font("���� ���", Font.PLAIN, 28));
		BB.setBounds(420, 25, 350, 50);
		add(BB);
		
		//�Խ����� �̸��� �����ִ� ���̺�
		filenameLabel = new JLabel();
		filenameLabel.setFont(new Font("���� ���", Font.BOLD, 20));
		filenameLabel.setBounds(660, 35, 200, 30);
		add(filenameLabel);
		
		//�Խ��� �ؽ�Ʈ���� - ������ ������ ������ ����ڰ� �ۼ��ϴ� ��
		BulletinBoard = new JTextArea();
		BulletinBoard.setFont(new Font("���� ���", Font.PLAIN, 20));
		BulletinBoard.setEnabled(true);
		JScrollPane scrollPane = new JScrollPane(BulletinBoard);
		scrollPane.setBounds(200, 90, 800, 490);
		add(scrollPane);
		
		//�����ϱ� ��ư - ��ư�� ������ ������ ���ϸ��� �����ǰ�, ���ϸ��� �ߺ� ���θ� �Ǵ��Ͽ� ������ ������
		JButton saveButton = new JButton("�����ϱ�");
		saveButton.setBounds(50, 500, 100, 30);
		saveButton.setBackground(new Color(255, 137, 132));
		add(saveButton);
		saveButton.addActionListener(new ActionListener() {
			@Override
			//������ �����Ϸ��� �õ��� ���
			public void actionPerformed(ActionEvent e) {
				try {
					//���ϸ��� �ߺ��� �ƴ� ���
					if(!MainActivity.doesfilealreadyexist(filename)) {				
						File newFile = new File("BulletinBoard", filename);
						BufferedWriter bw = new BufferedWriter(new FileWriter(newFile, false));			//false : ������ �̹� �����ϴ� ��� ������ ���
						PrintWriter pw = new PrintWriter(bw, true);										//true : ������ ������ �ڿ� �̾ ��
						pw.write(BulletinBoard.getText());												//JTextArea���� ������ ������ pw��ü�� ���� �ؽ�Ʈ���Ͽ� �ۼ�
						bw.close();
						pw.close();	
						JOptionPane.showMessageDialog(null, "���� �Ϸ�", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
						//���������� ����� �����ϳ�, �б�� �Ұ����ϹǷ� �����ư�� ������ 1�� �� ����ȭ������ ���ư���.
						Thread.sleep(1000);			//������ �Ͻ����� 1000ms(=1s)
						BulletinBoard.setText("");	//�Խ��� ���� �ʱ�ȭ
						initCombo();				//�޺��ڽ� ���� �ʱ�ȭ
						win.MainActivity.init();	//MainActivity�� �޺��ڽ��� ����Ʈ�� �����ϱ� ����
						win.goback();				//�ڷ� ���ư���.
					}
					//���ϸ��� �ߺ��� ���
					else
						JOptionPane.showMessageDialog(null, "�����̸� �ߺ�", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (FileNotFoundException exc) {			//������ ã�� ���� ����
					JOptionPane.showMessageDialog(null, "������ �� �� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (IOException exc) {					//���� IO ����
					JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (InterruptedException exc) {			//�����尡 �ߴܵǾ��� �� �߻��ϴ� ����. ������� �����尡 ����� ���� �� �߻�
					System.out.println(exc.getMessage());
				}
			}
		});
	}
	
	private void initCombo() {
		eventFlag = false;	//itemStateChanged�� �۵����� �ʱ� ���� eventFlag�� ���� false�� ����
		VariationCombo.setSelectedIndex(0);
		eventFlag = true;	//itemStateChanged�� �ٽ� �۵��ϵ��� �ϱ� ���� eventFlag�� ���� true�� ����
	}
	
	//�ܺο��� ȣ���� �� �ֵ��� public���� ����
	public void init() {
		filename = MainActivity.filename + ".txt";
		setInfoLabel();				//ȭ�鿡 �α��� �� ����� ����(ID, ����) ���
		setFilename();				//ȭ�鿡 �޺��ڽ����� ������ �������� �ݿ��� ���������� ���
	}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>�� ���� ����<br><BR/>" + "ID : " + Login.id + "<br/>" + "Level : " + Login.authority + "</html>");
	}
	
	private void setFilename() {
		filenameLabel.setText("��   " + filename);
	}
}
