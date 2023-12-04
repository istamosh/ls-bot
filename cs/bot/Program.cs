//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;
using System.Runtime.InteropServices; //DllImport
using System.Diagnostics; //Process

namespace bot
{
    class Program
    {
        // Import DynLib for getting process names
        [DllImport("User32.dll")]
        static extern int SetForegroundWindow(IntPtr pointer);
        static void Main(string[] args){
            // find process by name w/o .exe
            string processName = "lostsaga";
            
            // Try to find certain process
            Process[] process = Process.GetProcessesByName(processName);
            // Console.WriteLine(process.Length);
            // foreach (var p in process){
            //     Console.WriteLine(p);
            // }
            
            // Get the firstmost process
            Process losaha = process.FirstOrDefault();
            Console.WriteLine(losaha);

            // check if process is exist
            if (losaha != null){
                Console.WriteLine("Bringing window on focus...");
                IntPtr windowHandler = losaha.MainWindowHandle;
                SetForegroundWindow(windowHandler);
            }
            // Bringing window on focus doesn't work

            Console.WriteLine("Press key to exit..");
            Console.ReadKey();
        }
    }
}
