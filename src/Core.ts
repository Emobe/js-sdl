import net from 'net';

export default class Core {
    socketPath: string = '/tmp/.X11-unix/X0'
    client: net.Socket
    display: number;
    screen: number;

    constructor(display: number, screen: number, options: any){
        this.screen = screen;
        this.display = display;
        console.log(this.socketPath)
    }

    connect(){
        console.log(this.socketPath)
        this.client = net.createConnection(this.socketPath)
        this.client.on('connect', this.onConnect)
        this.client.on('error', this.onError)
    }

    onConnect(display: any){
        console.log('connected!')
        console.log(display)
    }

    onError(err: any){
        console.error(err)
    }

}