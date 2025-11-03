int loadData(ifstream &inFile, char songs[][2][MAXCHAR], int otherData[][2], int &count) {

    // Skip header line
    char temp[MAXCHAR];
    cout << "Temp: " << temp << endl;
    inFile.getline(temp, MAXCHAR, '\n');

    while (!inFile.eof() && count < SONGS) {
        // Skip Date
        inFile.ignore(5, ',');
        
        // Read position
        inFile >> otherData[count][0];
        inFile.ignore(5, ',');

        // Read song
        inFile.getline(songs[count][0], MAXCHAR, ',');
        
        // Read artist
        inFile.getline(songs[count][1], MAXCHAR, ',');

        // Skip popularity
        inFile.ignore(5, ',');

        // Read duration_ms
        inFile >> otherData[count][1];
        inFile.ignore(5, ',');

        // Skip rest
        inFile.ignore(5, ',');
        inFile.ignore(5, ',');
        inFile.ignore(5, ',');
        inFile.ignore(5, ',');
        inFile.ignore(5, '\n');

        // Increment count
        count++;

        // Read next song name from next line (first field)
        if (count < SONGS) {
            inFile.getline(songs[count][0], MAXCHAR, ',');
        }
    }

    return count;
}