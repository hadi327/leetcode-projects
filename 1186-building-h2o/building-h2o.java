import java.util.concurrent.Semaphore;
import java.util.concurrent.CyclicBarrier;

class H2O {
    private Semaphore hydrogen = new Semaphore(2);
    private Semaphore oxygen = new Semaphore(1);

    private CyclicBarrier barrier = new CyclicBarrier(3, () -> {
        hydrogen.release(2);
        oxygen.release(1);
    });

    public H2O() {
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hydrogen.acquire();

        releaseHydrogen.run();

        try {
            barrier.await();
        } catch (Exception e) {
            Thread.currentThread().interrupt();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oxygen.acquire();

        releaseOxygen.run();

        try {
            barrier.await();
        } catch (Exception e) {
            Thread.currentThread().interrupt();
        }
    }
}