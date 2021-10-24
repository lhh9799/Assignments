package test;
import java.util.*;

// 각 프로세스의 필요한 정보를 관리하는 클래스
class Process {
	private String name;		// 프로세스 이름
	private int arrivalTime;	// 프로세스 도착시간
	private int serviceTime;	// 프로세스 서비스시간, 실행시간 해야 할 총 시간
	private int executionTime;	// 프로세스의 현재까지 실행된 시간

	Process(String name, int arrivalTime, int serviceTime) { // 프로세스의 각 필드를 초기화함
		/* 각 멤버를 여기서 초기화 할 것 */
		this.name = name;
		this.arrivalTime = arrivalTime;
		this.serviceTime = serviceTime;
		executionTime = 0;
	}
	/* 아래 각 함수를 구현할 것 */
	public void	   incExecTime() 			{	/* 프로세스의 실행시간을 증가시킴 */
		executionTime++;
	}
	public int     getWaitingTime(int cTime){	/* 대기시간을 계산해 옴 */
		return cTime - arrivalTime;				//대기시간 = 현재시간 - 도착시간
	}
	public int     getRemainingTime()		{	/* 남을 실행시간을 계산해 옴 */
		return serviceTime - executionTime;
	}
	public String  getName()  				{	/* 프로세스의 이름을 얻어옴 */
		return name;
	}
	public boolean isFinished()				{	/* 프로세스의 실행이 종료되었는지 체크함 */
		if(serviceTime == executionTime)
			return true;
		else
			return false;
	}
}

// 시스템 내의 프로세스의 생성 등을 제어하는 클래스
// 모든 멤버가 static 멤버이며, 이 클래스의 객체는 생성되지 않는다.
class ProcessController {
	// 도착할 각 프로세스의 이름, 도착시간, 서비스시간 등을 배열로 관리함
	static private String processNames[] = { "A", "B", "C", "D", "E", "A", "B", "C", "D", "E" };
	static private int    arrivalTimes[] = {   0,   2,   4,   6,   8, 30,   32,  34,  36,  38 };
	static private int    serviceTimes[] = {   3,   6,   4,   5,   2,  6,    3,   4,   5,   2 };
	static private int	  index; // 다음 번에 도착할 프로세스의 위 배열 인덱스

	static public void    reset()          { index = 0; } // 각 스케줄러의 생성자에서 이 함수를 호출함, 처음부터 다시 스케줄링을 시작하고자 하는 경우 호출
	static public boolean hasNextProcess() { return index < arrivalTimes.length; } // 아직 도착하지 않은 프로세스가 더 있는지 조사

	// 매 시간단위마다 호출되며, 각 프로세스의 도착시간에 해당 프로세스를 생성하여 리턴함
	static public Process checkNewProcessArrival(int currentTime) {
		if ((index < arrivalTimes.length) && 			// 아직 도착할 프로세스(index)가 남아 있는 경우
			(arrivalTimes[index] == currentTime)) {		// 현재시간이 다음 프로세스(index)의 도착시간과 동일한 경우
			int i = index++;							// 인덱스 값을 증가시켜 그 다음 프로세스를 가르키게 함
			return new Process(processNames[i], arrivalTimes[i], serviceTimes[i]); // 해당 프로세스를 생성하여 반환함
		}
		return null; // 아직 다음 프로세스가 도착할 시간이 아닌 경우 null을 리턴함
	} 
}

// 스케줄러의 기본 틀: 이 추상클래스를 상속받아 각 스케줄링 알고리즘을 구현해야 함
abstract class Scheduler {
	private String name;						// 스케줄러 이름
	protected int currentTime;					// 현재시간
	protected Process currentProcess; 			// 현재 실행되고 있는 프로세스의 레퍼런스 변수
	protected boolean isNewProcessArrived;		// 현재시간에 새로운 프로세스가 도착한 경우 true, 아니면 false 
	protected LinkedList<Process> readyQueue;	// ready 상태의 모든 프로세스들을 모아 놓은 ready queue
	
	Scheduler(String name) { // 스케줄러의 각 필드를 초기화함
		this.name = name;
		currentTime = -1;
		currentProcess = null;
		isNewProcessArrived = false;
		readyQueue = new LinkedList<Process>();
		ProcessController.reset(); // 프로세스 제어자를 초기화함, 처음부터 다시 스케줄링하고자 할 경우 반드시 호출
	}
	public void addReadyQueue(Process p) { // ready queue에 새로운 프로세스 추가
		readyQueue.add(p); // 큐의 맨 끝에 프로세스 p 삽입
	}
	public boolean isThereAnyProcessToExecute() { // 모든 프로세스들의 실행이 종료되었는지 체크
		// 새로 도착할 프로세스가 있거나 또는 현재 실행되는 프로세스가 있거나, 또는 ready queue가 비어 있지 않은 경우 아직 끝나면 안됨 (true 반환)
		// 새로 도착할 프로세스가 없고 현재 실행되는 프로세스가 없고 ready queue가 비어 있으면 종료해도 됨 (false 반환)
		return(ProcessController.hasNextProcess() || (currentProcess != null) || !readyQueue.isEmpty());
	}
	public String getName() { return name; } // 스케줄러 이름 반환

	// 새로 스케줄링하여 다음에 실행할 우선순위가 가장 높은 프로세스를 선택함
	// 각 스케줄링 알고리즘별로 이 함수를 재정의하여야 함(오버라이딩)
	public void schedule() {
		if ((currentProcess != null) && currentProcess.isFinished()) { // 현재 실행중인 프로세스의 실행이 완료된 경우
			readyQueue.remove(currentProcess); // 현재 프로세스(currentProcess)를 ready queue에서 제거함
			currentProcess = null;
		}
		// 각 스케줄링 알고리즘별로 이 함수를 재정의해야 함. 재정의 함수에서 super클래스의 이 함수를 제일 먼저 호출해야 하며, 
		// 이 함수에서 리턴된 후 우선순위가 가장 높은 프로세스를 선택해야 함. SRT클래스의 schedule() 함수 참조.
	}
	
	// 매 시간 단위마다 호출되는 함수. 매 시간단위마다 clock interrupt가 들어와 실행된다고 생각하면 됨
	// 각 스케줄링 알고리즘별로 이 함수를 재정의해야 함. 재정의 함수에서 super클래스의 이 함수를 제일 먼저 호출해야 함
	public void clockInterrupt() {
		currentTime++; // 현재시간을 1 증가함
		if (currentProcess != null) { // 현재 실행되고 있는 프로세스가 있다면
			currentProcess.incExecTime(); // 현재 실행되는 프로세스의 실행시간을 1 증가함
			System.out.print(currentProcess.getName()); // 실행되는 프로세스의 이름을 출력함
		}
		else
			System.out.print(" "); // 현재 실행되는 프로세스가 없을 경우 출력

		Process p = ProcessController.checkNewProcessArrival(currentTime); // 새로운 프로세스가 도착했는지 체크
		isNewProcessArrived = (p != null); // p는 새로 도착한 프로세스 객체
		if (isNewProcessArrived)
			addReadyQueue(p); // 새로 도착한 프로세스를 ready queue의 맨 끝에 추가
	}
}

// Shortest Remaining Next 알고리즘을 구현
class SRT extends Scheduler { // 각 스케줄링 알고리즘은 Scheduler 클래스를 상속 받아서 구현해야 함
	SRT(String name) { super(name); } //  Scheduler 클래스의 생성자 호출

	// Scheduler 클래스의 schedule()을 재정의, 여기서 다음에 실행할 우선순위가 가장 높은 프로세스를 선택함
	@Override
	public void schedule() { 
		super.schedule(); // 수퍼 클래스인 Scheduler의 schedule()을 먼저 호출해야 함, 여기서 현재 프로세스가 실행이 종료되었으면 먼저 제거됨
		Process nextProcess = readyQueue.peek(); // ready 큐의 헤드에 있는 원소를 반환 (삭제하지는 않음) , or return null
		// ready queue에 있는 프로세스들 중 remaining time이 가장 적은 프로세스(우선순위가 가장 높은 프로세스)를 찾는다.
		for (var p: readyQueue) // ready queue의 각각의 프로세스 p에 대해 
			if (p.getRemainingTime() < nextProcess.getRemainingTime())
				nextProcess = p; // 현재까지  remaining time이 가장 적은 프로세스임
		currentProcess = nextProcess; // 새로 선택된 가장 우선순위가 높은 프로세스임. 이 프로세스가 실행됨
		// 실제 시스템에서는 여기서 currentProcess에게 CPU를 넘김.
	}

	// 매 시간 단위마다 호출되는 함수. 매 시간단위마다 clock interrupt가 들어와 실행된다고 생각하면 됨
	// 각 스케줄링 알고리즘별로 이 함수를 재정의해야 함. 
	@Override
	public void clockInterrupt() {
		super.clockInterrupt(); // super클래스(Scheduler)의 이 함수를 제일 먼저 호출해야 함
		// 인터럽트의 맨 마지막에 적절한 조건(새로운 프로세스 도착 또는 현 작업 종료)이 만족되면 schedule() 함수를 호출함
		// 이 알고리즘은 선점형(Preemptive) 알고리즘임
		if ( isNewProcessArrived ||  // 새로운 프로세스가 도착했거나 또는
		     ((currentProcess != null) && currentProcess.isFinished()) ) // 현재 실행중인 작업이 종료되었거나 
			schedule(); // 새로 스케줄링하여 우선순위가 가장 높은 프로세스를 선택하여 그 프로세스를 실행시킴
	}
}

// Round Robin 알고리즘을 구현
class RR extends Scheduler {
	private int quantum;    // RR 알고리즘의 time quantum, time slice
	private int execTime;   // 현재 프로세스가 지금껏 실행된 시간, quantum 보다 작아야 하며 동일하면 time slice를 모두 소진한 것임
							// 이 값은 매 시간 단위마다 1씩 증가함
	
	RR(String name, int qauntum) { 
		super(name);    // Scheduler 클래스의 생성자 호출
		this.quantum = qauntum; // RR 알고리즘의 time quantum, time slice
		execTime = 0;
	}
	
	/*  아래 두 함수를 재정의 하여야 함(오버로딩)
	public void schedule(), public void clockInterrupt()

	ready queue 조작을 위해 다음의 함수를 사용할 수 있음
	boolean readyQueue.add(Process p); // 큐의 맨 끝에 p 삽입, return true or throw IllegalStateException
	Process readyQueue.remove() // 큐의 맨 앞쪽에 있는 프로세스를 삭제한 후 이를 반환, or throw NoSuchElementException
	*/
	
	@Override
	public void schedule() {						// super에서 현재 실행중인 작업이 끝난 경우를 if로 처리하였으니 여기선 실행중인 작업이 끝나지 않은 경우도 정의해아함.
		super.schedule();							// 수퍼 클래스인 Scheduler의 schedule()을 먼저 호출해야 함, 여기서 현재 프로세스가 실행이 종료되었으면 먼저 제거됨
		execTime = 0;								// 실행시간 0으로 초기화
		readyQueue.add(currentProcess);				// 실행중이던(아직 완료되지 않은) 작업을 readyQueue 맨 뒤에 추가함
		readyQueue.remove(currentProcess);			// 현재 실행중이던 작업을 readyQueue에서 제거함
		Process nextProcess = readyQueue.peek();	// ready 큐의 헤드에 있는 원소를 반환 (삭제하지는 않음) , or return null
		currentProcess = nextProcess;				// 새로 선택된 가장 우선순위가 높은 프로세스임. 이 프로세스가 실행됨
	}
	
	@Override
	public void clockInterrupt() {
		super.clockInterrupt();											// super클래스(Scheduler)의 이 함수를 제일 먼저 호출해야 함
		execTime++;														// 실행시간 증가
		if ((currentProcess != null) && currentProcess.isFinished())	// 현재 실행중인 작업이 종료된 경우
			schedule();
		else if ((currentProcess != null) && execTime == quantum)		// 현재 실행중인 작업이 있고, quantum을 다 쓴 경우
			schedule();
		else if (currentProcess == null && isNewProcessArrived)			// 현재 실행중인 작업이 없고, 새로운 작업이 도착한 경우
			schedule();
	}
}

public class SchedulingApp_20164269 {

	public static void printEpilog(Scheduler scheduler) {
		/* 화면에 다음과 같이 출력함: 알고리즘 이름 scheduler.getName()
		Scheduling Algorithm: 알고리즘이름
		0         1         2         3         4         5    	// 시간 십단위
		0123456789012345678901234567890123456789012345678901234 // 시간 일단위
		*/
		/* 위 처럼 출력되게 여기에 코딩하라 */
		int i, j;
		System.out.print("Scheduling Algoritm: " + scheduler.getName() + "\n");
		for(i=0; i<6; i++)							//십단위 시간을 출력
			System.out.print(i + "         ");
		System.out.print("\n");						//줄바꿈
		for(i=0; i<6; i++) {						//일단위 시간을 출력
			if(i!=5) {								//i=5가 아닌경우(즉 i가 0부터 4까지). 0부터 9까지의 숫자를 반복해서 출력
				for(j=0; j<10; j++)
					System.out.print(j);
			}
			else									//i=5인 경우.
				for(j=0; j<i; j++)					//j를 i보다 작은수인 4까지 출력
					System.out.print(j);
		}
		System.out.print("\n");						//줄바굼
	}

	public static void schedAppRun(Scheduler scheduler) { // 각 스케줄링 알고리즘을 테스트 함
		printEpilog(scheduler); // 화면에 단위시간 눈금자를 출력함

		while (scheduler.isThereAnyProcessToExecute()) { // 아직 더 실행해야 할 프로세스가 있는지 체크
			scheduler.clockInterrupt(); // 매 시간단위마다 스케줄러의 clock interrupt handler를 호출함
			try {					// 매 시간단위는 100ms
				Thread.sleep(100); 	// 100 millisecond 동안 대기상태, 즉 100ms마다 한번씩 위 scheduler.clockInterrupt()가 호출됨
			}
			catch (InterruptedException e) { // sleep()하는 동안 다른 스레드에 의해 인터럽이 들어 온 경우, 여기서는 전혀 발생하지 않음 
				e.printStackTrace(); // InterruptedException이 발생했을 경우 지금껏 호출된 함수 리스트를 출력해 볼 수 있음
				return;
			}
		}
		System.out.println("\n");
	}
	
	public static void main(String[] args) {
		schedAppRun(new SRT("SRT")); // SRT 스케줄러 객체를 생성한 후 스케줄링 알고리즘을 테스트 함
		/* 아래 // 주석을 해제한 후 사용하라. */
		schedAppRun(new RR("RR q=1", 1));
		schedAppRun(new RR("RR q=4", 4));
	}
}