// http://www.careercup.com/question?id=6751316000899072
import java.util.concurrent.Semaphore;

public class FooBar {
	public int n = 100;
	private Semaphore sharedSemaphore;
	private Semaphore exclusiveSemaphore;

	public FooBar(int n) {
		// TODO Auto-generated constructor stub
		this.n = n;
		this.sharedSemaphore = new Semaphore(n);
		this.exclusiveSemaphore = new Semaphore(1);
	}

	public void reader() {
		// The reader here is not to return a value, but to perform read()
		// action. Thus it is 'void reader()'.
		while (exclusiveSemaphore.availablePermits() < 1) {
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		try {
			sharedSemaphore.acquire();
			System.out.println("Performing read() operation.");
			sharedSemaphore.release();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void writer() {
		while (exclusiveSemaphore.availablePermits() < 1
				&& sharedSemaphore.availablePermits() < n) {
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		try {
			exclusiveSemaphore.acquire();
			System.out.println("Performing write() operation.");
			exclusiveSemaphore.release();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		FooBar fooBar = new FooBar(100);

		fooBar.reader();
		fooBar.writer();
	}
}
