let serial = require("serial");
let notify = require("notification");
serial.setup("usart", 115200);

let ssid = "yourssid";
let password = "yourpassword";

let message = ssid + ":" + password + "\n";

let cycle = 0;
while(cycle < 100){
    let counter = 0;
    let store = "";

    while (counter < 100) {
        let rx_data = serial.readBytes(1, 0);
        if (rx_data !== undefined) {
            let data_view = Uint8Array(rx_data);
            for (let i = 0; i < data_view.length; i++) {
                store += chr(data_view[i])
            }
        }
        counter++;
    }

    if(store !== "")
        print(store);

    cycle++;
}

serial.write("test");

serial.write(message)
notify.error();
 delay(1000);
notify.success();
 delay(1000);
for (let i = 0; i < 4; i++) {
    notify.blink("green", "short");
    delay(100);
}    