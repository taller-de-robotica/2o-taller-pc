import tkinter as tk
import tkinter.font as tkFont
import socket

# Wifi
UDP_IP = "000.000.0.000" # Indicar IP
UDP_PORT = 0000 # Indicar puerto
sock = socket.socket(socket.AF_INET, # Internet
                socket.SOCK_DGRAM) # UDP

class App:
    def __init__(self, root):        
        # Graphic interface
        root.title("Osoyoo control")
        #setting window size
        width = 430
        height = 380
        screenwidth = root.winfo_screenwidth()
        screenheight = root.winfo_screenheight()
        alignstr = '%dx%d+%d+%d' % (width, height, (screenwidth - width) / 2, (screenheight - height) / 2)
        root.geometry(alignstr)
        root.resizable(width = False, height = False)

        # Style
        ft = tkFont.Font(family = 'Times',size=10)
        bg_main = "#00ced1"
        fc_main = "#000000"
        bg_diagonal = "#90f090"
        bg_turn = "#ff8c00"

        # Buttons
        stop_button=tk.Button(root)
        stop_button["bg"] = bg_main
        stop_button["font"] = ft
        stop_button["fg"] = fc_main
        stop_button["justify"] = "center"
        stop_button["text"] = "Stop"
        stop_button.place(x = 170,y = 160,width = 80,height = 52)
        stop_button["command"] = self.stop_button_command

        left_button=tk.Button(root)
        left_button["bg"] = bg_main
        left_button["font"] = ft
        left_button["fg"] = fc_main
        left_button["justify"] = "center"
        left_button["text"] = "Left"
        left_button.place(x = 60,y = 160,width = 80,height = 52)
        left_button["command"] = self.left_button_command

        right_button=tk.Button(root)
        right_button["bg"] = bg_main
        right_button["font"] = ft
        right_button["fg"] = fc_main
        right_button["justify"] = "center"
        right_button["text"] = "Right"
        right_button.place(x = 280,y = 160,width = 80,height = 52)
        right_button["command"] = self.right_button_command

        forward_button=tk.Button(root)
        forward_button["bg"] = bg_main
        forward_button["font"] = ft
        forward_button["fg"] = fc_main
        forward_button["justify"] = "center"
        forward_button["text"] = "Forward"
        forward_button.place(x = 170,y = 80,width = 80,height = 52)
        forward_button["command"] = self.forward_button_command

        backward_button=tk.Button(root)
        backward_button["bg"] = bg_main
        backward_button["font"] = ft
        backward_button["fg"] = fc_main
        backward_button["justify"] = "center"
        backward_button["text"] = "Backward"
        backward_button.place(x = 170,y = 240,width = 80,height = 52)
        backward_button["command"] = self.backward_button_command

        d_left_up_button=tk.Button(root)
        d_left_up_button["bg"] = bg_diagonal
        d_left_up_button["font"] = ft
        d_left_up_button["fg"] = fc_main
        d_left_up_button["justify"] = "center"
        d_left_up_button["text"] = "D. L. Up"
        d_left_up_button.place(x = 80,y = 100,width = 55,height = 30)
        d_left_up_button["command"] = self.d_left_up_button_command

        d_right_up_button=tk.Button(root)
        d_right_up_button["bg"] = "#90ee90"
        d_right_up_button["cursor"] = "spider"
        d_right_up_button["font"] = ft
        d_right_up_button["fg"] = fc_main
        d_right_up_button["justify"] = "center"
        d_right_up_button["text"] = "D. R. Up"
        d_right_up_button.place(x = 280,y = 100,width = 55,height = 30)
        d_right_up_button["command"] = self.d_right_up_button_command

        d_right_down_button=tk.Button(root)
        d_right_down_button["bg"] = bg_diagonal
        d_right_down_button["font"] = ft
        d_right_down_button["fg"] = fc_main
        d_right_down_button["justify"] = "center"
        d_right_down_button["text"] = "D. R. D."
        d_right_down_button.place(x = 280,y = 240,width = 55,height = 30)
        d_right_down_button["command"] = self.d_right_down_button_command

        d_left_down_button=tk.Button(root)
        d_left_down_button["bg"] = bg_diagonal
        d_left_down_button["font"] = ft
        d_left_down_button["fg"] = fc_main
        d_left_down_button["justify"] = "center"
        d_left_down_button["text"] = "D. L. D."
        d_left_down_button.place(x = 80,y = 240,width = 55,height = 30)
        d_left_down_button["command"] = self.d_left_down_button_command

        l_turn_button=tk.Button(root)
        l_turn_button["bg"] = "#ff8c00"
        l_turn_button["font"] = ft
        l_turn_button["fg"] = "#ffffff"
        l_turn_button["justify"] = "center"
        l_turn_button["text"] = "Left turn"
        l_turn_button.place(x = 60,y = 320,width = 80,height = 25)
        l_turn_button["command"] = self.l_turn_button_command

        r_turn_button=tk.Button(root)
        r_turn_button["bg"] = "#ff8c00"
        ft = tkFont.Font(family = 'Times',size=10)
        r_turn_button["font"] = ft
        r_turn_button["fg"] = "#ffffff"
        r_turn_button["justify"] = "center"
        r_turn_button["text"] = "Right turn"
        r_turn_button.place(x = 280,y = 320,width = 80,height = 25)
        r_turn_button["command"] = self.r_turn_button_command


    def stop_button_command(self):
        print("Stop")


    def left_button_command(self):
        print("Moving left")


    def right_button_command(self):
        print("Moving right")


    def forward_button_command(self):
        print("Moving forward")


    def backward_button_command(self):
        print("Moving backward")


    def d_left_up_button_command(self):
        print("Diagonal left upwards")


    def d_right_up_button_command(self):
        print("Diagonal right upwards")


    def d_right_down_button_command(self):
        print("Diagonal right downwards")


    def d_left_down_button_command(self):
        print("Diagonal left downwards")


    def l_turn_button_command(self):
        print("Left turn")


    def r_turn_button_command(self):
        print("Right turn")
        self.send_message('r')

    def send_message(self, message):
        mes = bytes(message, 'ascii')
        sock.sendto(mes, (UDP_IP, UDP_PORT))


if __name__ == "__main__":
    print("UDP target IP: %s" % UDP_IP)
    print("UDP target port: %s" % UDP_PORT)

    root = tk.Tk()
    app = App(root)
    root.mainloop()
