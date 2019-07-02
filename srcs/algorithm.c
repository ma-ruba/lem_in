int algorithm()
{
    int i;

    i = 0;
    while (/*the number of connections between start room and others */ < i)
    {
        looking_for_the_shortest_path();
        i++;
    }
    moving_ants();
}

// struct for variants (including path (which ant is moving and what room it
//                      choose) and the number of lines)

// struct for shortests ways



void looking_for_the_shortest_path()
{
    //this function is going through our pathes (lists that are made of connections
            // between rooms that we readed) and compare their to find the
            // shortest way. then it put the result in a stucture, special made
            // for the results. So then when we call to this function next time
            // we will avoid the results that are in our structure

}

void moving_ants()
{
    // this functions is counting how much lines appeares if we are going
        //through out structure sertain way 
}