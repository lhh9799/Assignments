package test;
import java.util.*;

// �� ���μ����� �ʿ��� ������ �����ϴ� Ŭ����
class Process {
	private String name;		// ���μ��� �̸�
	private int arrivalTime;	// ���μ��� �����ð�
	private int serviceTime;	// ���μ��� ���񽺽ð�, ����ð� �ؾ� �� �� �ð�
	private int executionTime;	// ���μ����� ������� ����� �ð�

	Process(String name, int arrivalTime, int serviceTime) { // ���μ����� �� �ʵ带 �ʱ�ȭ��
		/* �� ����� ���⼭ �ʱ�ȭ �� �� */
		this.name = name;
		this.arrivalTime = arrivalTime;
		this.serviceTime = serviceTime;
		executionTime = 0;
	}
	/* �Ʒ� �� �Լ��� ������ �� */
	public void	   incExecTime() 			{	/* ���μ����� ����ð��� ������Ŵ */
		executionTime++;
	}
	public int     getWaitingTime(int cTime){	/* ���ð��� ����� �� */
		return cTime - arrivalTime;				//���ð� = ����ð� - �����ð�
	}
	public int     getRemainingTime()		{	/* ���� ����ð��� ����� �� */
		return serviceTime - executionTime;
	}
	public String  getName()  				{	/* ���μ����� �̸��� ���� */
		return name;
	}
	public boolean isFinished()				{	/* ���μ����� ������ ����Ǿ����� üũ�� */
		if(serviceTime == executionTime)
			return true;
		else
			return false;
	}
}

// �ý��� ���� ���μ����� ���� ���� �����ϴ� Ŭ����
// ��� ����� static ����̸�, �� Ŭ������ ��ü�� �������� �ʴ´�.
class ProcessController {
	// ������ �� ���μ����� �̸�, �����ð�, ���񽺽ð� ���� �迭�� ������
	static private String processNames[] = { "A", "B", "C", "D", "E", "A", "B", "C", "D", "E" };
	static private int    arrivalTimes[] = {   0,   2,   4,   6,   8, 30,   32,  34,  36,  38 };
	static private int    serviceTimes[] = {   3,   6,   4,   5,   2,  6,    3,   4,   5,   2 };
	static private int	  index; // ���� ���� ������ ���μ����� �� �迭 �ε���

	static public void    reset()          { index = 0; } // �� �����ٷ��� �����ڿ��� �� �Լ��� ȣ����, ó������ �ٽ� �����ٸ��� �����ϰ��� �ϴ� ��� ȣ��
	static public boolean hasNextProcess() { return index < arrivalTimes.length; } // ���� �������� ���� ���μ����� �� �ִ��� ����

	// �� �ð��������� ȣ��Ǹ�, �� ���μ����� �����ð��� �ش� ���μ����� �����Ͽ� ������
	static public Process checkNewProcessArrival(int currentTime) {
		if ((index < arrivalTimes.length) && 			// ���� ������ ���μ���(index)�� ���� �ִ� ���
			(arrivalTimes[index] == currentTime)) {		// ����ð��� ���� ���μ���(index)�� �����ð��� ������ ���
			int i = index++;							// �ε��� ���� �������� �� ���� ���μ����� ����Ű�� ��
			return new Process(processNames[i], arrivalTimes[i], serviceTimes[i]); // �ش� ���μ����� �����Ͽ� ��ȯ��
		}
		return null; // ���� ���� ���μ����� ������ �ð��� �ƴ� ��� null�� ������
	} 
}

// �����ٷ��� �⺻ Ʋ: �� �߻�Ŭ������ ��ӹ޾� �� �����ٸ� �˰����� �����ؾ� ��
abstract class Scheduler {
	private String name;						// �����ٷ� �̸�
	protected int currentTime;					// ����ð�
	protected Process currentProcess; 			// ���� ����ǰ� �ִ� ���μ����� ���۷��� ����
	protected boolean isNewProcessArrived;		// ����ð��� ���ο� ���μ����� ������ ��� true, �ƴϸ� false 
	protected LinkedList<Process> readyQueue;	// ready ������ ��� ���μ������� ��� ���� ready queue
	
	Scheduler(String name) { // �����ٷ��� �� �ʵ带 �ʱ�ȭ��
		this.name = name;
		currentTime = -1;
		currentProcess = null;
		isNewProcessArrived = false;
		readyQueue = new LinkedList<Process>();
		ProcessController.reset(); // ���μ��� �����ڸ� �ʱ�ȭ��, ó������ �ٽ� �����ٸ��ϰ��� �� ��� �ݵ�� ȣ��
	}
	public void addReadyQueue(Process p) { // ready queue�� ���ο� ���μ��� �߰�
		readyQueue.add(p); // ť�� �� ���� ���μ��� p ����
	}
	public boolean isThereAnyProcessToExecute() { // ��� ���μ������� ������ ����Ǿ����� üũ
		// ���� ������ ���μ����� �ְų� �Ǵ� ���� ����Ǵ� ���μ����� �ְų�, �Ǵ� ready queue�� ��� ���� ���� ��� ���� ������ �ȵ� (true ��ȯ)
		// ���� ������ ���μ����� ���� ���� ����Ǵ� ���μ����� ���� ready queue�� ��� ������ �����ص� �� (false ��ȯ)
		return(ProcessController.hasNextProcess() || (currentProcess != null) || !readyQueue.isEmpty());
	}
	public String getName() { return name; } // �����ٷ� �̸� ��ȯ

	// ���� �����ٸ��Ͽ� ������ ������ �켱������ ���� ���� ���μ����� ������
	// �� �����ٸ� �˰��򺰷� �� �Լ��� �������Ͽ��� ��(�������̵�)
	public void schedule() {
		if ((currentProcess != null) && currentProcess.isFinished()) { // ���� �������� ���μ����� ������ �Ϸ�� ���
			readyQueue.remove(currentProcess); // ���� ���μ���(currentProcess)�� ready queue���� ������
			currentProcess = null;
		}
		// �� �����ٸ� �˰��򺰷� �� �Լ��� �������ؾ� ��. ������ �Լ����� superŬ������ �� �Լ��� ���� ���� ȣ���ؾ� �ϸ�, 
		// �� �Լ����� ���ϵ� �� �켱������ ���� ���� ���μ����� �����ؾ� ��. SRTŬ������ schedule() �Լ� ����.
	}
	
	// �� �ð� �������� ȣ��Ǵ� �Լ�. �� �ð��������� clock interrupt�� ���� ����ȴٰ� �����ϸ� ��
	// �� �����ٸ� �˰��򺰷� �� �Լ��� �������ؾ� ��. ������ �Լ����� superŬ������ �� �Լ��� ���� ���� ȣ���ؾ� ��
	public void clockInterrupt() {
		currentTime++; // ����ð��� 1 ������
		if (currentProcess != null) { // ���� ����ǰ� �ִ� ���μ����� �ִٸ�
			currentProcess.incExecTime(); // ���� ����Ǵ� ���μ����� ����ð��� 1 ������
			System.out.print(currentProcess.getName()); // ����Ǵ� ���μ����� �̸��� �����
		}
		else
			System.out.print(" "); // ���� ����Ǵ� ���μ����� ���� ��� ���

		Process p = ProcessController.checkNewProcessArrival(currentTime); // ���ο� ���μ����� �����ߴ��� üũ
		isNewProcessArrived = (p != null); // p�� ���� ������ ���μ��� ��ü
		if (isNewProcessArrived)
			addReadyQueue(p); // ���� ������ ���μ����� ready queue�� �� ���� �߰�
	}
}

// Shortest Remaining Next �˰����� ����
class SRT extends Scheduler { // �� �����ٸ� �˰����� Scheduler Ŭ������ ��� �޾Ƽ� �����ؾ� ��
	SRT(String name) { super(name); } //  Scheduler Ŭ������ ������ ȣ��

	// Scheduler Ŭ������ schedule()�� ������, ���⼭ ������ ������ �켱������ ���� ���� ���μ����� ������
	@Override
	public void schedule() { 
		super.schedule(); // ���� Ŭ������ Scheduler�� schedule()�� ���� ȣ���ؾ� ��, ���⼭ ���� ���μ����� ������ ����Ǿ����� ���� ���ŵ�
		Process nextProcess = readyQueue.peek(); // ready ť�� ��忡 �ִ� ���Ҹ� ��ȯ (���������� ����) , or return null
		// ready queue�� �ִ� ���μ����� �� remaining time�� ���� ���� ���μ���(�켱������ ���� ���� ���μ���)�� ã�´�.
		for (var p: readyQueue) // ready queue�� ������ ���μ��� p�� ���� 
			if (p.getRemainingTime() < nextProcess.getRemainingTime())
				nextProcess = p; // �������  remaining time�� ���� ���� ���μ�����
		currentProcess = nextProcess; // ���� ���õ� ���� �켱������ ���� ���μ�����. �� ���μ����� �����
		// ���� �ý��ۿ����� ���⼭ currentProcess���� CPU�� �ѱ�.
	}

	// �� �ð� �������� ȣ��Ǵ� �Լ�. �� �ð��������� clock interrupt�� ���� ����ȴٰ� �����ϸ� ��
	// �� �����ٸ� �˰��򺰷� �� �Լ��� �������ؾ� ��. 
	@Override
	public void clockInterrupt() {
		super.clockInterrupt(); // superŬ����(Scheduler)�� �� �Լ��� ���� ���� ȣ���ؾ� ��
		// ���ͷ�Ʈ�� �� �������� ������ ����(���ο� ���μ��� ���� �Ǵ� �� �۾� ����)�� �����Ǹ� schedule() �Լ��� ȣ����
		// �� �˰����� ������(Preemptive) �˰�����
		if ( isNewProcessArrived ||  // ���ο� ���μ����� �����߰ų� �Ǵ�
		     ((currentProcess != null) && currentProcess.isFinished()) ) // ���� �������� �۾��� ����Ǿ��ų� 
			schedule(); // ���� �����ٸ��Ͽ� �켱������ ���� ���� ���μ����� �����Ͽ� �� ���μ����� �����Ŵ
	}
}

// Round Robin �˰����� ����
class RR extends Scheduler {
	private int quantum;    // RR �˰����� time quantum, time slice
	private int execTime;   // ���� ���μ����� ���ݲ� ����� �ð�, quantum ���� �۾ƾ� �ϸ� �����ϸ� time slice�� ��� ������ ����
							// �� ���� �� �ð� �������� 1�� ������
	
	RR(String name, int qauntum) { 
		super(name);    // Scheduler Ŭ������ ������ ȣ��
		this.quantum = qauntum; // RR �˰����� time quantum, time slice
		execTime = 0;
	}
	
	/*  �Ʒ� �� �Լ��� ������ �Ͽ��� ��(�����ε�)
	public void schedule(), public void clockInterrupt()

	ready queue ������ ���� ������ �Լ��� ����� �� ����
	boolean readyQueue.add(Process p); // ť�� �� ���� p ����, return true or throw IllegalStateException
	Process readyQueue.remove() // ť�� �� ���ʿ� �ִ� ���μ����� ������ �� �̸� ��ȯ, or throw NoSuchElementException
	*/
	
	@Override
	public void schedule() {						// super���� ���� �������� �۾��� ���� ��츦 if�� ó���Ͽ����� ���⼱ �������� �۾��� ������ ���� ��쵵 �����ؾ���.
		super.schedule();							// ���� Ŭ������ Scheduler�� schedule()�� ���� ȣ���ؾ� ��, ���⼭ ���� ���μ����� ������ ����Ǿ����� ���� ���ŵ�
		execTime = 0;								// ����ð� 0���� �ʱ�ȭ
		readyQueue.add(currentProcess);				// �������̴�(���� �Ϸ���� ����) �۾��� readyQueue �� �ڿ� �߰���
		readyQueue.remove(currentProcess);			// ���� �������̴� �۾��� readyQueue���� ������
		Process nextProcess = readyQueue.peek();	// ready ť�� ��忡 �ִ� ���Ҹ� ��ȯ (���������� ����) , or return null
		currentProcess = nextProcess;				// ���� ���õ� ���� �켱������ ���� ���μ�����. �� ���μ����� �����
	}
	
	@Override
	public void clockInterrupt() {
		super.clockInterrupt();											// superŬ����(Scheduler)�� �� �Լ��� ���� ���� ȣ���ؾ� ��
		execTime++;														// ����ð� ����
		if ((currentProcess != null) && currentProcess.isFinished())	// ���� �������� �۾��� ����� ���
			schedule();
		else if ((currentProcess != null) && execTime == quantum)		// ���� �������� �۾��� �ְ�, quantum�� �� �� ���
			schedule();
		else if (currentProcess == null && isNewProcessArrived)			// ���� �������� �۾��� ����, ���ο� �۾��� ������ ���
			schedule();
	}
}

public class SchedulingApp_20164269 {

	public static void printEpilog(Scheduler scheduler) {
		/* ȭ�鿡 ������ ���� �����: �˰��� �̸� scheduler.getName()
		Scheduling Algorithm: �˰����̸�
		0         1         2         3         4         5    	// �ð� �ʴ���
		0123456789012345678901234567890123456789012345678901234 // �ð� �ϴ���
		*/
		/* �� ó�� ��µǰ� ���⿡ �ڵ��϶� */
		int i, j;
		System.out.print("Scheduling Algoritm: " + scheduler.getName() + "\n");
		for(i=0; i<6; i++)							//�ʴ��� �ð��� ���
			System.out.print(i + "         ");
		System.out.print("\n");						//�ٹٲ�
		for(i=0; i<6; i++) {						//�ϴ��� �ð��� ���
			if(i!=5) {								//i=5�� �ƴѰ��(�� i�� 0���� 4����). 0���� 9������ ���ڸ� �ݺ��ؼ� ���
				for(j=0; j<10; j++)
					System.out.print(j);
			}
			else									//i=5�� ���.
				for(j=0; j<i; j++)					//j�� i���� �������� 4���� ���
					System.out.print(j);
		}
		System.out.print("\n");						//�ٹٱ�
	}

	public static void schedAppRun(Scheduler scheduler) { // �� �����ٸ� �˰����� �׽�Ʈ ��
		printEpilog(scheduler); // ȭ�鿡 �����ð� �����ڸ� �����

		while (scheduler.isThereAnyProcessToExecute()) { // ���� �� �����ؾ� �� ���μ����� �ִ��� üũ
			scheduler.clockInterrupt(); // �� �ð��������� �����ٷ��� clock interrupt handler�� ȣ����
			try {					// �� �ð������� 100ms
				Thread.sleep(100); 	// 100 millisecond ���� ������, �� 100ms���� �ѹ��� �� scheduler.clockInterrupt()�� ȣ���
			}
			catch (InterruptedException e) { // sleep()�ϴ� ���� �ٸ� �����忡 ���� ���ͷ��� ��� �� ���, ���⼭�� ���� �߻����� ���� 
				e.printStackTrace(); // InterruptedException�� �߻����� ��� ���ݲ� ȣ��� �Լ� ����Ʈ�� ����� �� �� ����
				return;
			}
		}
		System.out.println("\n");
	}
	
	public static void main(String[] args) {
		schedAppRun(new SRT("SRT")); // SRT �����ٷ� ��ü�� ������ �� �����ٸ� �˰����� �׽�Ʈ ��
		/* �Ʒ� // �ּ��� ������ �� ����϶�. */
		schedAppRun(new RR("RR q=1", 1));
		schedAppRun(new RR("RR q=4", 4));
	}
}