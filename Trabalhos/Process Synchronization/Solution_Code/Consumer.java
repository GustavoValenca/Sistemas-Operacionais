package Solution_Code;

import java.util.Random;
public class Consumer implements Runnable {
    private final Dropbox dropbox;
    private final boolean even;

    public Consumer(boolean even, Dropbox dropbox) {
        this.even = even;
        this.dropbox = dropbox;
    }
    
    public void run() {
        Random random = new Random();
        while (true) {
            
            // < await (p > c);
            while (dropbox.p == dropbox.c){
                continue;
            }

            // verificação de paridade
            if (dropbox.getEvenNumber() == this.even){
                dropbox.take(even);
                dropbox.c += 1;
            }
            
            try {
               Thread.sleep(random.nextInt(100));
            } catch (InterruptedException e) { }
        }
    }
}
