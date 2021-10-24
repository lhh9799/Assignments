import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

//�α����ϴ� ȭ���� �����ϴ� ��Ƽ��Ƽ
class LoginActivity extends JPanel {
	private MyJPanel win;
	private JTextField ID;
	private JPasswordField PW;
	private Login login;
	
	public LoginActivity(MyJPanel win) {
		this.win = win;		//main�Լ��� MyJPanel�� ���� win�� LoginActivity��ü�� MyJPanel�� ���� win�� ���� -> ���� win.change �޼ҵ带 ����ϱ� ����
		setLayout(null);
		login = new Login();
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.DARK_GRAY, 5), "="));
		
		//Ÿ��Ʋ ���̺�
		JLabel title = new JLabel("�� ���ĵѶ� ���α׷�");
		title.setFont(new Font("���� ���", Font.PLAIN, 35));
		title.setBounds(390, 15, 400, 100);
		add(title);
		
		//���� �г�
		JPanel inst = new JPanel();
		inst.setLayout(null);
		inst.setBounds(60, 110, 960, 300);
		inst.setBackground(new Color(150, 190, 190));
		inst.setBorder(new LineBorder(Color.LIGHT_GRAY, 2));
		//���� �гο� �߰��� �̹���
		Image image = new ImageIcon("bellimage.jpg").getImage();
		Image chimage = image.getScaledInstance(800, 150, Image.SCALE_SMOOTH);
		JLabel imageLabel = new JLabel(new ImageIcon(chimage));
		imageLabel.setBounds(90, 15, 800, 150);
		//���� �гο� �߰��� ��
		JLabel instLabel = new JLabel("<html>�� ���ĵѶ� ���� ������ ������ �𵨷� ������ ��å�� ���� ���� �����ϴ� �𵨷ν�, ���� ��å�� ������ ���� �������� ���� ������ �帣�� ���� �����մϴ�. ������ ���� ������ ���� ������ ��м��� ���� ���� ���谡 ���е� ������ ��ȣ�ϱ� ���� ����մϴ�. <br> bell-lapadula ���� �������� ��Ģ�� no read up, no write down��, ���� ����� �����ڴ� ���� ����� ������ ���� �� ���� ���� ����� �����ڴ� ���� ����� ������ ������ �� �����ϴ�.<html/>");
		instLabel.setFont(new Font("�����ٸ����", Font.PLAIN, 15));
		instLabel.setBounds(20, 155, 900, 150);
		inst.add(instLabel);
		inst.add(imageLabel);		
		add(inst);
		
		//���̵� ���̺�
		JLabel IDLabel = new JLabel("ID");
		IDLabel.setBounds(400, 440, 80, 20);
		add(IDLabel);
		
		//���̵� �ؽ�Ʈ�ʵ�
		ID = new JTextField();
		ID.setBounds(490, 440, 116, 21);
		ID.setColumns(12);
		add(ID);
		//���̵� �ؽ�Ʈ�ʵ�� ��Ŀ��
		ID.requestFocus();
		win.addWindowListener(new WindowAdapter() { 
			public void windowOpened( WindowEvent e ) { 
				ID.requestFocus(); 
			} 
		});
		
		//��й�ȣ ���̺�
		JLabel PWLabel = new JLabel("password");
		PWLabel.setBounds(400, 470, 80, 20);
		add(PWLabel);
		
		//��й�ȣ �н������ʵ�
		PW = new JPasswordField();
		PW.setBounds(490, 470, 116, 21);
		PW.addActionListener(new MyActionListener());
		add(PW);
		
		//�α��� ��ư
		JButton LoginButton = new JButton("�α���");
		LoginButton.setFont(new Font("���� ���", Font.BOLD, 13));
		LoginButton.setSize(80, 40);
		LoginButton.setLocation(625, 450);
		LoginButton.setBackground(new Color(255, 137, 132));
		LoginButton.addActionListener(new MyActionListener());
		add(LoginButton);
		
		//ȸ������ ���̺�
		JLabel RegisterLabel = new JLabel("ȸ���� �ƴϽŰ���?");
		RegisterLabel.setFont(new Font("���� ���", Font.BOLD, 12));
		RegisterLabel.setBounds(420, 530, 150, 20);
		add(RegisterLabel);
		
		//ȸ������ ��ư
		JButton RegisterButton = new JButton("ȸ������");
		RegisterButton.setFont(new Font("���� ���", Font.BOLD, 11));
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
		
//		//�� ���� ���� - deprecated
//		ID.setNextFocusableComponent(PW);
//		PW.setNextFocusableComponent(LoginButton);
	}
	
	//�α��� �õ� ���� �Ͼ�� �׼�
	class MyActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			//�Ϲ� �������� �α��� ���� ��
			if(login.verify(ID.getText(), PW.getText())) {
				win.change("MainActivity", "LoginActivity");
				setTextfieldClear();
				System.out.println("�α��� ���� ID = " + Login.id + ", authority = " + Login.authority);
			}
			//admin �������� �α��� ���� ��
			else if((ID.getText().equals("admin")) && PW.getText().equals("admin")) {
				login.id = "admin";
				setTextfieldClear();
				win.change("AuthorizationActivity", "LoginActivity");
			}
			//�α��� ���� ��
			else if((ID.getText().equals("") && PW.getText().equals("")))
				JOptionPane.showMessageDialog(null, "���̵�, ��й�ȣ�� �Է��ϼ���", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			else if((ID.getText().equals("")))
				JOptionPane.showMessageDialog(null, "���̵� �Է��ϼ���", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			else if((PW.getText().equals("")))
				JOptionPane.showMessageDialog(null, "��й�ȣ�� �Է��ϼ���", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			else
				JOptionPane.showMessageDialog(null, "ȸ������ ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	private void setTextfieldClear() {
		ID.setText("");
		PW.setText("");
	}
}