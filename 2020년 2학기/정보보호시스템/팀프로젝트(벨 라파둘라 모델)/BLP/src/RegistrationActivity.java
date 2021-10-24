import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

//ȸ������ ȭ���� �����ϴ� ��Ƽ��Ƽ
public class RegistrationActivity extends JPanel {
	private boolean check = false;		//�ߺ�Ȯ�� ���θ� �Ǵ��ϴ� ����
	private JTextField ID;
	private JPasswordField PW;
	private Registration r = new Registration();
	
	public RegistrationActivity(MyJPanel win) {
		setLayout(null);
		setBackground(new Color(183, 215, 216));
		setBorder(new TitledBorder(new LineBorder(Color.BLACK, 5), "="));
		
		//��Ƽ��Ƽ Ÿ��Ʋ ���̺�
		JLabel title = new JLabel("ȸ������");
		title.setFont(new Font("���� ���", Font.PLAIN, 35));
		title.setBounds(480, 80, 400, 100);
		add(title);
		
		//���̵� ���̺�
		JLabel IDLabel = new JLabel("ID");
		IDLabel.setBounds(400, 250, 67, 15);
		add(IDLabel);
		//���̵� �ؽ�Ʈ�ʵ�
		ID = new JTextField();
		ID.setBounds(485, 250, 116, 21);
		add(ID);
		ID.setColumns(12);
		
		//��й�ȣ ���̺�
		JLabel PWLabel = new JLabel("password");
		PWLabel.setBounds(400, 280, 67, 15);
		add(PWLabel);
		//��й�ȣ �н����� �ʵ�
		PW = new JPasswordField(15);
		PW.setBounds(485, 280, 116, 21);
		add(PW);
		
		//�ڷΰ��� ��ư
		JButton BackButton = new JButton("�ڷΰ���");
		BackButton.setBounds(50, 560, 100, 20);
		BackButton.setBackground(new Color(237, 247, 245));
		add(BackButton);
		BackButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ID.setText("");	PW.setText("");
				win.goback();
			}
		});
		
		//�����ϱ� ��ư
		JButton RegistrationButton = new JButton("�����ϱ�");
		RegistrationButton.setFont(new Font("���� ���", Font.BOLD, 13));
		RegistrationButton.setSize(90, 40);
		RegistrationButton.setLocation(628, 320);
		RegistrationButton.setBackground(new Color(255, 137, 132));
		add(RegistrationButton);
		RegistrationButton.addActionListener(new ActionListener() {
			@Override
			//������ �õ��� ���
			public void actionPerformed(ActionEvent e) {
				//���̵� ������ ������ ���(���� X, �ߺ� X, �ߺ�Ȯ�� �Ϸ�)
				if((!ID.getText().equals("")) && (!PW.getText().equals("")) && (r.redundancyCheck(ID.getText()) == false) && check == true) {
					check = false;
					r.register(ID.getText(), PW.getText());
					JOptionPane.showMessageDialog(null, "���� �Ϸ�", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
				//���̵� ������ �Ұ����� ���
				else if(check == false)
					JOptionPane.showMessageDialog(null, "�ߺ�Ȯ���� �Ϸ���� �ʾҽ��ϴ�.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else if(ID.getText().equals(""))
					JOptionPane.showMessageDialog(null, "���̵� �����Դϴ�.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else if(PW.getText().equals(""))
					JOptionPane.showMessageDialog(null, "��й�ȣ�� �����Դϴ�.", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else
					JOptionPane.showMessageDialog(null, "���̵� �ߺ�", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
			}
		});
		
		//�ߺ�Ȯ�� ��ư
		JButton redundancyCheck = new JButton("�ߺ�Ȯ��");
		redundancyCheck.setFont(new Font("���� ���", Font.BOLD, 11));
		redundancyCheck.setSize(90, 20);
		redundancyCheck.setLocation(630, 250);
		redundancyCheck.setBackground(new Color(255, 198, 168));
		add(redundancyCheck);
		redundancyCheck.addActionListener(new ActionListener() {
			@Override
			//ID �ߺ�Ȯ���� �õ��� ���
			public void actionPerformed(ActionEvent e) {
				//�ߺ�Ȯ�� ���� �� (���� �õ��� ���̵� �����̰ų� �ߺ��� ���)
				if(ID.getText().equals("") || ID.getText().equals("admin"))
					JOptionPane.showMessageDialog(null, "���̵� �ٽ� �Է��ϼ���", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				else if(r.redundancyCheck(ID.getText()) == true)
					JOptionPane.showMessageDialog(null, "���̵� �ߺ�", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
				//�ߺ�Ȯ�� ���� ��
				else {
					check = true;
					JOptionPane.showMessageDialog(null, "��� ������ ���̵�", "INFO_MESSAGE", JOptionPane.INFORMATION_MESSAGE);
				}
			}
		});
	}
}