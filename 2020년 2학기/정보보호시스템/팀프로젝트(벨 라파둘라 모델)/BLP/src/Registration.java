import java.io.*;
import javax.swing.JOptionPane;		//�޽��� �ڼ� ��¿�

//ȸ�������� ���� �޼ҵ���� ������ class
public class Registration {
	
	//ȸ������ �޼ҵ�
	public void register(String ID, String PW) {
		//���� �ؽ�Ʈ ���Ͽ� ȸ�������� ȸ���� ������ ����
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter("MemberInfo.txt", true));	//false : ������ �̹� �����ϴ� ��� ������ ���
			PrintWriter pw = new PrintWriter(bw, true);										//true : ������ ������ �ڿ� �̾ ��
			pw.write(ID + "\t" + PW + "\t" + "3" + System.getProperty("line.separator"));	//������ ȸ���� ������ 3���� ����
			bw.close();																		//��Ʈ�� ����
		}
		//������ ã�� ���� ���
		catch (FileNotFoundException e) {		//������ ã�� ���� ����
			JOptionPane.showMessageDialog(null, "������ �� �� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		//���� ����� ���� ������ �� ���
		catch (IOException e) {					//���� IO ����
			JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	//ID �ߺ�Ȯ�� �޼ҵ� - �ߺ��� ��� true�� �ƴ� ��� false ����
	public boolean redundancyCheck(String ID) {
		try {
			File info = new File("MemberInfo.txt");							//ȸ������ ���� ���
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(info), "UTF-8"));	//�ѱ��� �б� ���� "UTF-8"�� ���ڵ�
			
			String currentLine;
			//ȸ������ ���Ͽ� �߰��ϰ��� �ϴ� ID�� �����ϴ��� Ȯ�� (�����ϸ� �ߺ��̹Ƿ� true ����)
			while((currentLine = br.readLine()) != null){
				if(currentLine.contains(ID)) {								//�о�� �ٿ��� ��ġ�ϴ� ID�� ã�� ���
					if(ID.equals(currentLine.split("\t")[0])) {	
						br.close();
						return true;
					}
				}
			}
			br.close();		
		}
		catch (FileNotFoundException exc) {									//������ ã�� ���� ����
			JOptionPane.showMessageDialog(null, "������ �� �� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		catch (IOException exc) {											//���� IO ����
			JOptionPane.showMessageDialog(null, "����� ����", "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
		}
		return false;
	}
}