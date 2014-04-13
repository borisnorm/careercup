// http://www.careercup.com/question?id=6366101810184192
import java.util.concurrent.Semaphore;

public class FooBar {
	public static final int MAX_CONCURRENT_READ = 100;
	private Semaphore sharedSemaphore;
	private Semaphore exclusiveSemaphore;

	public FooBar() {
		// TODO Auto-generated constructor stub
		this.sharedSemaphore = new Semaphore(MAX_CONCURRENT_READ);
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
				&& sharedSemaphore.availablePermits() < MAX_CONCURRENT_READ) {
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
		FooBar fooBar = new FooBar();

		fooBar.reader();
		fooBar.writer();
	}
}
