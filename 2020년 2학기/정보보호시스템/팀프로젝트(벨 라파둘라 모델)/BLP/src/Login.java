import java.io.*;
import javax.swing.JOptionPane;

//�α��� ���� ���� �Լ��� ������ �ִ� class
public class Login {
	static int authority;
	static String id;

	//ȸ������ ���Ͽ��� ��ġ�ϴ� ������ ã�� ��� true, ã�� ���� ��� false ����
	public boolean verify(String ID, String PW) {
		String STR;
		String tokens[];
		
		try {
			File file = new File("MemberInfo.txt");
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file), "UTF-8"));	//�ѱ��� �б� ���� "UTF-8"�� ���ڵ�
			
			while((STR = br.readLine()) != null) {
				if(STR.contains(ID)) {									//������ ID�� ã�� ���
					tokens = STR.split("\t");							//��ū �ڸ� - 0�� : ���̵� 1�� : ��й�ȣ, 2�� : ����
					if(ID.equals(tokens[0]) && PW.equals(tokens[1])) {	//���̵�� ��й�ȣ�� ��ġ�ϴ� ���
						id = tokens[0];									//static������ ID�� �α����� ȸ���� ID ����
						authority = Integer.parseInt(tokens[2]);		//static������ authority�� �α����� ȸ���� ������ ����
						br.close();										//��Ʈ�� ����
						return true;									
					}
				}
			}
			br.close();	//��Ʈ�� ����
		return false;
		}
		catch (FileNotFoundException e) {								//������ ã�� ���� ����
			JOptionPane.showMessageDialog(null, "ȸ������ ���� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException e) {											//���� IO ����
			JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		return false;
	}
}
