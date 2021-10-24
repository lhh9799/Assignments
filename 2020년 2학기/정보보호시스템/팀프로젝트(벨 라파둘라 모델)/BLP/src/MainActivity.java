import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import java.io.File;

//�α��� ����, ���� ���� �� �۾� ���� ȭ���� �����ϴ� ��Ƽ��Ƽ
public class MainActivity extends JPanel {
	private JLabel IDLabel;
	private String [] actions = {"�۾� ����", "����", "�б�"};
	private JComboBox<String> typeCombo = new JComboBox<String>();
	private JComboBox<String> actionCombo = new JComboBox<String>(actions);
	private boolean eventFlag = true;		//itemStateChanged�� �۵��� �Ͻ������ϱ� ���� ��ġ
	static String filename;
	private int target1, target2;
	
	public MainActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//��Ƽ��Ƽ Ÿ��Ʋ ���̺�
		JLabel title = new JLabel("���� �� �۾� ����");
		title.setFont(new Font("���� ���", Font.PLAIN, 35));
		title.setBounds(420, 80, 400, 100);
		add(title);
		
		//�α�����  id �� ���� ��� ���̺�
		IDLabel = new JLabel();
		IDLabel.setFont(new Font("���� ���", Font.BOLD, 15));
		IDLabel.setBounds(30, 30, 100, 80);
		add(IDLabel);
		
		//�α׾ƿ� ��ư
		JButton LogoutButton = new JButton("�α׾ƿ�");
		LogoutButton.setFont(new Font("���� ���", Font.BOLD, 11));
		LogoutButton.setBounds(170, 31, 100, 20);
		LogoutButton.setBackground(new Color(237, 247, 245));
		add(LogoutButton);
		LogoutButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				win.logout();
			}
		});
				
		//�Խ��� �̸��� �����ϴ� type�޺��ڽ�
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
					target1 = Character.getNumericValue(filename.charAt(3));	//���õ� ������ �̸����� ������ ������
				}
			}
		});
		
		//�۾��� �����ϴ� action�޺��ڽ�
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
		
		//�Խ��� �� �۾��� ������ �� ���� ��Ƽ��Ƽ�� �Ѿ�� ���� Ȯ�� ��ư
		JButton ConfirmButton = new JButton("Ȯ��");
		LogoutButton.setFont(new Font("���� ���", Font.BOLD, 11));
		ConfirmButton.setBounds(623, 255, 80, 20);
		ConfirmButton.setBackground(new Color(255, 198, 168));
		add(ConfirmButton);
		ConfirmButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//�޺��ڽ��� �������� ���� ���
				if(target1 != 0 && target2 != 0) {
//					filename += ".txt";
					switch(target2) {
					//�޺��ڽ����� ���⸦ ������ ���
					case 1	:
						if(Login.authority > target1) {								//ȸ���� ������ �Խ����� �������� ���ڰ� ū ��� ��,�ۼ� ������ ���
							JOptionPane.showMessageDialog(null, "������ �̹� �ֽ��ϴ�.\n���� �̸��� �����ϼ���.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
							win.change("WritingActivity", "MainActivity");
							break;
						}
						//ȸ���� ������ �Խ����� �������� ���ڰ� ���� ��� ��,�ۼ� �Ұ����� ���
						else {	
							JOptionPane.showMessageDialog(null, "���Ⱑ �Ұ����� �����Դϴ�.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
							break;
						}
					//�޺��ڽ����� �б⸦ ������ ���
					case 2 :
						if(Login.authority < target1) {								//ȸ���� ������ �Խ����� �������� ���ڰ� ���� ��� ��, �б� ������ ���
							win.change("ReadingActivity", "MainActivity");
							break;
							}
						
						else {														//ȸ���� ������ �Խ����� �������� ���ڰ� ���� ��� ��, �б� �Ұ����� ���
							JOptionPane.showMessageDialog(null, "�бⰡ �Ұ����� �����Դϴ�.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
							break;
						}
					}
				}
				//�޺��ڽ��� ���õ��� ���� ���
				else {
					JOptionPane.showMessageDialog(null, "�޺��ڽ� ���þȵ�", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
			}
		});
	}
	
	//�޺��ڽ����� ������ ������ �̸��� �̹� �����ϴ��� Ȯ���ϴ� �޼ҵ�. �����ϸ� true, �������� ������ false ����
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
	
	//�ܺο��� ȣ���� �� �ֵ��� public���� ����
	public void init() {
		typeCombo.removeAllItems();	//���� MainActivity�� �ٽ� ȣ��Ǿ��� �� ���ο� ���� ����Ʈ�� �����ϱ� ���� �޺��ڽ� �ʱ�ȭ
		addFileName();				//�޺��ڽ��� ���� ����Ʈ�� �߰�
		setInfoLabel();				//ȭ�鿡 �α��� �� ����� ����(ID, ����) ���
	}
	
	//���� ����� �о�� ���� ���� �޺��ڽ�(typeCombe)�� �ִ� �޼ҵ�
		private void addFileName() {
			File dir = new File("BulletinBoard");
			File[] fileList = dir.listFiles();
				
			typeCombo.addItem("���� ����");
			for(int i=0; i<fileList.length; i++) {
				String file = fileList[i].getName();
				typeCombo.addItem(file.split("\\.")[0]);
			}
		}
	
	private void setInfoLabel() {
		IDLabel.setText("<html>�� ���� ����<br><BR/>" + "ID : " + Login.id + "<br/>" + "Level : " + Login.authority + "</html>");
	}
}
