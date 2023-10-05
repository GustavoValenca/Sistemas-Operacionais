package Solution_Code;

import java.util.Random;

public class Producer implements Runnable {

    private Dropbox dropbox;

    public Producer(Dropbox dropbox) {
        this.dropbox = dropbox;
    }

    public void run() {
        Random random = new Random();
        while (true) {
            // < await (p == c); >
            while (dropbox.p > dropbox.c){
                continue;
            }

            int number = random.nextInt(10);
            
            try {
                Thread.sleep(random.nextInt(100));
                dropbox.put(number);
                dropbox.p += 1;
            } catch (InterruptedException e) { }
        }
    }
}
