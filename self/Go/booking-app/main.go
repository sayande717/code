package main
import "fmt"

func main() {
    // Variables
    var conferenceName string = "Go Conference" // variable
    const conferenceTickets = 50         // Constants
    var remainingTickets uint = 50
    // Variables without value
    var userName string
    var userTickets int

    // Minimal definition
    //temp := 20

    
    // Printing variables, spaces get added automatically
    fmt.Printf("Welcome to %v Booking Application\n",conferenceName) // f=format
    
    fmt.Println("Welcome to", conferenceName, "Booking Application. We have",remainingTickets,"tickets out of",conferenceTickets, "available.")
    fmt.Println("Get your tickets here!")

    userName = "Tom"
    userTickets = 2
    fmt.Printf("User %v booked %v tickets.\n",userName,userTickets)
    fmt.Printf("username is of type %T.",userName)
    fmt.Println(temp)

}
