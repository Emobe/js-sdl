import net from 'net';
export default class Client {
    socket: net.Socket;
    constructor(connection: net.Socket){
        this.socket = connection;
    }

}