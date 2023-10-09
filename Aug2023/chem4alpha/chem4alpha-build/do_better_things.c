



struct myItem { 
  int id;
  string name;
  vector<double> time;
  vector<double> sumG;  
};


void do_better_things() {



           //id  /item
  std::map<int,myItem> mymap;

  cout << "hello!" << endl;


  TFile *infile = TFile::Open("Species.root");
  TTree *tree   = (TTree*)infile->Get("species");

  tree->Print();

  char   name[64];
  int    id;
  double t;
  double sumG;



  tree->SetBranchAddress("speciesName",&name);
  tree->SetBranchAddress("speciesID",&id);
  tree->SetBranchAddress("time",&t);
  tree->SetBranchAddress("sumG",&sumG);


  std::vector<int>    idVec;
  std::vector<double> tVec;
  std::vector<double> sumGVec;
 

  for(long x=0;x<tree->GetEntries();x++) {
    tree->GetEntry(x);
    //if(!mymap.count[id]) {
      mymap[id].id = id;
      mymap[id].name = name;
    //}
    mymap[id].time.push_back(t);
    mymap[id].sumG.push_back(sumG);
  }


  map<int,myItem>::iterator it;
  TCanvas *c = new TCanvas;
  c->Divide(4,2);
  int pad=1;
  for(it=mymap.begin();it!=mymap.end();it++) {
    printf("%s\n",it->second.name.c_str());
    myItem item = it->second;
    TGraph *gr = new TGraph(item.time.size(),item.time.data(),item.sumG.data());
    gr->SetTitle(item.name.c_str());
    c->cd(pad++);
    gPad->SetLogx();
    gr->Draw("A*");
  }




}
