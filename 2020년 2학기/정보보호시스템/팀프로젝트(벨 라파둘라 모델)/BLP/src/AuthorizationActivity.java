import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

//���� �����ϴ� ȭ���� �����ϴ� ��Ƽ��Ƽ
class AuthorizationActivity extends JPanel {
	private JLabel IDLabel;
	private String [] Level = {"����", "1", "2", "3", "4", "5", "6"};
	private String targetID = "";		//������ ����� ��� ID
	private int targetLevel;			//������ ���� ��
	private JComboBox<String> IDCombo = new JComboBox<String>();
	private JComboBox<String> LevelCombo = new JComboBox<String>(Level);

	public AuthorizationActivity (MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		JLabel title = new JLabel("���� ����");
		title.setFont(new Font("���� ���", Font.PLAIN, 35));
		title.setBounds(480, 80, 400, 100);
		add(title);
		
		//���� ������ ���̵� ������ �� �ִ� ID�޺��ڽ�
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
		
		//������ ������ �� �ִ� Level�޺��ڽ�
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
		
		//�α׾ƿ� ��ư
		JButton LogoutButton = new JButton("�α׾ƿ�");
		LogoutButton.setBounds(170, 40, 100, 20);
		LogoutButton.setBackground(new Color(237, 247, 245));
		add(LogoutButton);
		LogoutButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				IDCombo.removeAllItems();
				win.logout();
			}
		});
		
		//���� ���� ���̺�
		IDLabel = new JLabel();
		IDLabel.setFont(new Font("���� ���", Font.BOLD, 15));
		IDLabel.setBounds(30, 30, 100, 80);
		add(IDLabel);
		
		//���� ���� ��ư
		JButton ApplyButton = new JButton("�����ϱ�");
		ApplyButton.setBounds(643, 255, 90, 20);
		ApplyButton.setBackground(new Color(255, 198, 168));
		add(ApplyButton);
		//���� ���� �õ� ���� �Ͼ�� �׼�
		ApplyButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					//�޺��ڽ��� ���� �� �׸��� �����ϰ� ������ ���
					if((targetID != null) && (!targetID.equals("���̵�") && (targetLevel != 0))) {
						System.out.println("============================");
						File info = new File("MemberInfo.txt");									//ȸ�������� �ִ� ���� ���
						File temp = new File("temp.txt");										//����� ������ ���� ���� ���� �ӽ� ����
						//���� ���� ���Ͽ��� �о�� �ӽ� ���Ͽ� �ۼ��ϴ� ���� ����
						BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(info), "UTF-8"));				//�ѱ��� �б� ���� "UTF-8"�� ���ڵ�
						BufferedWriter bw = new BufferedWriter(new FileWriter(temp));
						
						String currentLine;
						while((currentLine = br.readLine()) != null){
							//��ġ�ϴ� ���̵� ã�� ��� ���� ���� ��
							if(currentLine.contains(targetID)) {								// ������ ID�� ã�� ���
								String tokens[] = currentLine.split("\t");
								if(targetID.equals(tokens[0])) {								//txt������ ID���� tokens[0]�� �޺��ڽ��� targetID�� ��ġ�ϴ��� ��
									bw.write(tokens[0] + "\t" + tokens[1] + "\t" + targetLevel + System.getProperty("line.separator"));	//����� ȸ������ ����
									System.out.println("renewLine | " + tokens[0] + "\t" + tokens[1] + "\t" + targetLevel);
								}
							}
							//��ġ�ϴ� ���̵� ã�� ���� ���
							else {	
								bw.write(currentLine + System.getProperty("line.separator"));	//���� ������ �� ���й���(line.separator)�� �����ϱ� ���� getProperty�޼ҵ� ����Ͽ� �ۼ�
								System.out.println(" keepLine | " + currentLine);
							}
						}
						System.out.println("============================");
						bw.close();			
						br.close();					
						info.delete();						//���� ���� ���� ��,
						temp.renameTo(info);				//���� �ۼ��� �ӽ������� �̸��� ������ �����̸����� ����
						JOptionPane.showMessageDialog(null, "���� �Ϸ�", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);	
					}
					//�޺��ڽ��� �������� �ʾҰų�, �޺��ڽ��� ���� �� �׸��� ������ ���
					else
						JOptionPane.showMessageDialog(null, "�޺��ڽ� ���þȵ�", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
				catch (FileNotFoundException exc) {			//������ ã�� ���� ����
					JOptionPane.showMessageDialog(null, "������ �� �� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
				catch (IOException exc) {					//���� IO ����
					JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				}
			}
		});
	}
	
	//�ܺο��� ȣ���� �� �ֵ��� public���� ����
	public void init() {
		addName();									//MemberInfo.txt���Ͽ��� ID�� ������ IDComboBox�� �߰�
		setInfoLabel();								//ȭ�鿡 �α��� �� �������� ����(ID) ���
	}
	
	//MemberInfo.txt���Ͽ��� ID�� ������ IDComboBox�� �߰��ϴ� �޼ҵ�
	private void addName() {
		String STR;										//MemberInfo.txt���� �� �پ� �б� ���� String�� ���� STR ����
		
		try {
			File file = new File("MemberInfo.txt");
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file), "UTF-8"));	//�ѱ��� �б� ���� "UTF-8"�� ���ڵ�
			
			IDCombo.addItem("���̵�");
			while((STR = br.readLine()) != null) {
				IDCombo.addItem(STR.split("\t")[0]);	//��ū �ڸ� - 0�� : ���̵� 1�� : ��й�ȣ, 2�� : ����
			}
			br.close();									//��Ʈ�� ����
		}
		catch (FileNotFoundException exce) {			//������ ã�� ���� ����
			JOptionPane.showMessageDialog(null, "ȸ������ ���� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException exce) {						//���� IO ����
			JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>�� ���� ����<br><BR/>" + "ID : " + Login.id + "</html>");
	}
}