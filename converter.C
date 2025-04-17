{
    TGraph *gr1 = new TGraph();
    ifstream ifile;
    ofstream ofile;
    double a, b, c, d, e, f;  // a = nr. primului canal al liniei curente de date
    std::vector<double> counts;
    string filename;
    bool exist = false;

    cout << "\n----------------------------" << endl;
    cout << "|   CONVERTOR TXT -> ASC   |" << endl;
    cout << "----------------------------" << endl;

    cout << "\nIntroduceti nume fisier .txt (fara extensia .txt): "; cin >> filename;
    ifile.open((filename + ".txt").c_str());
    if(!ifile) { cout << "Nu exista fisierul tastat ..." << endl << endl; }
    if(ifile) { exist = true; }
    while(true && ifile)
    {
        ifile >> a >> b >> c >> d >> e >> f;
        if(ifile.eof()) break;
        counts.push_back(b);
        counts.push_back(c);
        counts.push_back(d);
        counts.push_back(e);
        counts.push_back(f);
    }
    ifile.close();

    if(exist)  // salvare date si plotare doar daca exista fisierul de input
    {
        ofile.open((filename + "_o.ASC").c_str());  // ASCII file
        for(int i=0; i<counts.size(); i++)
        {
            gr1->SetPoint(i, i, counts[i]);
            ofile << counts[i] << endl;
        }
        ofile.close();
    

        bool plotare = true;
        if(plotare)
        {
            // --- Plotare rezultat ---
            TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
            c1->SetGrid();
            gr1->SetLineColor(kBlue);
            gr1->SetLineWidth(2);
            gr1->GetXaxis()->SetTitle("canal");
            gr1->GetYaxis()->SetTitle("impulsuri");
            gr1->Draw("AL");
            c1->Update();
        }
    }
}
