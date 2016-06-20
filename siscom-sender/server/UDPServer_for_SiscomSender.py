import socket

UDP_IP = raw_input('Host IP [Default: localhost]: ')
if not UDP_IP:
    UDP_IP = 'localhost'

UDP_PORT = raw_input('Port Number [Default: 22000]: ')
if not UDP_PORT:
    UDP_PORT = 22000

UDP_PORT = int(UDP_PORT)
sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
                     
sock.bind((UDP_IP, UDP_PORT))

print "Server OnLine"

filename = ""
receiving_file = 0
received = 0
Exit = 1
while Exit:
    #data, addr = sock.recv(1024) # buffer size is 1024 bytes
    data, addr = sock.recvfrom(2048) # buffer size is 1024 bytes
    #print '[IP: %s, Port: %s] Received message: %s' %(addr[0],addr[1],data) 
    #print data    
    
    
    #print received
    if (data == "123FILE321"):
        #filename, addr = sock.recvfrom(2048)
        #data, addr = sock.recvfrom(2048)
        msg, addr = sock.recvfrom(2048)
        msg = msg.split("/")
        filename = msg[-1]
        print "RECEBENDO ARQUIVO DE: ", addr
        print "Nome do Arquivo:  ", filename
        f = open(filename,'w')
        receiving_file = 1
    
    
    elif (data == "123CLOSE321"):
        print "\nArquivo recebido: ", filename
        print "Verifique o arquivo na pasta onde este script se encontra."
        receiving_file = 0
        f.close()
        #Exit = 0
    
    elif(receiving_file == 1):
        data=bytearray(data)
        f.write(data) # python will convert \n to os.linesep
    
    else:
        data=bytearray(data)
        print (data)
    

print "Fechando tudo.."
sock.close()
