#include <QCoreApplication>
#include <QDebug>
#include <QTime>

//"Vector erase time (milliseconds): 41415"
//"Vector insert time (milliseconds): 42324"
//"Vector sort time (milliseconds): 252"

//"List erase time (milliseconds): 26"
//"List insert time (milliseconds): 32"
//"List sort time (milliseconds): 677"

//"Map erase time (milliseconds): 40"
//"Map insert time (milliseconds): 101"

bool compare(int vecVal, int foundVal) {
    return vecVal < foundVal;
}

double qMyRand() {
    return qrand() % 1000;
}

int itemCount = 500000;
int processStep = 10000;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    typedef std::vector<int> Ints;
    Ints digitVec = { 4, 7, 10, 3, 2, 11, 3, 5, 8, 22, 34};
    std::sort(digitVec.begin(), digitVec.end());

    auto found = std::lower_bound(digitVec.begin(), digitVec.end(), 22, compare);
    if(found == digitVec.end()) {
        qDebug() << "Value is not found!!!";
    }
    else {
        qDebug() << "Value is found!!!";
    }


    typedef std::list<double> DblList;
    typedef std::vector<double> DblVec;
    typedef std::map<int, double> DblMap;

    // initialize
    DblVec doubleVec;
    DblList doubleList;
    DblMap doubleMap;
    for(int i = 0; i < itemCount; ++i) {
        int rand = qMyRand();

        doubleVec.push_back(rand);
        doubleList.push_back(rand);
        doubleMap.insert(std::make_pair(i, (double)rand));
    }


    //////////////////////////////////////////////////
    // vector process

    {
        typedef std::vector<DblVec::iterator> DblVecIts;
        DblVecIts dblVecIts;

        int index = 0;
        auto vend = doubleVec.end();
        for(auto vit = doubleVec.begin(); vit != vend; ++vit, ++index) {
            if(index % processStep == 0)
                dblVecIts.push_back(vit);
        }

        QTime vecTimer;
        vecTimer.start();

        auto divend = dblVecIts.rend();
        for(auto divit = dblVecIts.rbegin(); divit != divend; ++divit) {
            doubleVec.erase(*divit);
        }

        int vecEraseTime = vecTimer.elapsed();
        qDebug() << "Vector erase time (milliseconds): " + QString::number(vecEraseTime);


        /////////////////////////////
        // insert

        QTime vecInsertTimer;
        vecInsertTimer.start();

        index = 0;
        for(auto vit = doubleVec.begin(); vit != doubleVec.end(); ++vit, ++index) {
            if(index % processStep == 0) {
                int rand = qMyRand();
                doubleVec.insert(vit, rand);
            }
        }

        int vecInsertTime = vecInsertTimer.elapsed();
        qDebug() << "Vector insert time (milliseconds): " + QString::number(vecInsertTime);

        /////////////////////////////
        // sort

        QTime vecSortTimer;
        vecSortTimer.start();

        std::sort(doubleVec.begin(), doubleVec.end());

        int vecSortTime = vecSortTimer.elapsed();
        qDebug() << "Vector sort time (milliseconds): " + QString::number(vecSortTime);

        /////////////////////////////
        // search

        index = int(int(doubleVec.size()) / 4 * 3);
        int find = doubleVec[index];

        QTime vecSearchTimer;
        vecSearchTimer.start();

        auto foundIt = std::lower_bound(doubleVec.begin(), doubleVec.end(), find);
//        auto foundIt = std::find(doubleVec.begin(), doubleVec.end(), find);

        int vecSearchTime = vecSearchTimer.elapsed();

        if(foundIt != doubleVec.end())
            qDebug() << "Vector search time (milliseconds): " + QString::number(vecSearchTime) + " Value to find: "
                        + QString::number(find) + ", found: " + QString::number(*foundIt);

        qDebug() << "";
    }


    /////////////////////////////////////////////////////////
    // list erase

    {
        typedef std::vector<DblList::iterator> DblListIts;
        DblListIts dblListIts;

        int index = 0;
        auto lend = doubleList.end();
        for(auto lit = doubleList.begin(); lit != lend; ++lit, ++index) {
            if(index % processStep == 0)
                dblListIts.push_back(lit);
        }

        QTime listTimer;
        listTimer.start();

        auto dilend = dblListIts.rend();
        for(auto dilit = dblListIts.rbegin(); dilit != dilend; ++dilit) {
            doubleList.erase(*dilit);
        }

        int listEraseTime = listTimer.elapsed();
        qDebug() << "List erase time (milliseconds): " + QString::number(listEraseTime);


        /////////////////////////////
        // insert

        QTime listInsertTimer;
        listInsertTimer.start();

        index = 0;
        for(auto lit = doubleList.begin(); lit != doubleList.end(); ++lit, ++index) {
            if(index % processStep == 0) {
                int rand = qMyRand();
                doubleList.insert(lit, rand);
            }
        }

        int listInsertTime = listInsertTimer.elapsed();
        qDebug() << "List insert time (milliseconds): " + QString::number(listInsertTime);

        /////////////////////////////
        // sort

        QTime listSortTimer;
        listSortTimer.start();

        doubleList.sort();

        int listSortTime = listSortTimer.elapsed();
        qDebug() << "List sort time (milliseconds): " + QString::number(listSortTime);


        /////////////////////////////
        // search

        index = int(itemCount / 3 * 2);

        QTime listAdvanceTimer;
        listAdvanceTimer.start();

        auto lit = doubleList.begin();
        std::advance(lit, index);
        double find = *lit;

        int advanceTime = listAdvanceTimer.elapsed();
        qDebug() << "List advance time (milliseconds): " + QString::number(advanceTime);

        QTime listSearchTimer;
        listSearchTimer.start();

        auto foundIt = std::lower_bound(doubleList.begin(), doubleList.end(), find);

        int listSearchTime = listSearchTimer.elapsed();

        if(foundIt != doubleList.end())
            qDebug() << "List search time (milliseconds): " + QString::number(listSearchTime);

        qDebug() << "";
    }


    //////////////////////////////////////////////////
    // map process

    {
        typedef std::vector<DblMap::iterator> DblMapIts;
        DblMapIts dblMapIts;

        double index = 0.0;
        auto mend = doubleMap.end();
        for(auto mit = doubleMap.begin(); mit != mend; ++mit, ++index) {
            if((int)index % processStep == 0)
                dblMapIts.push_back(mit);
        }

        QTime mapTimer;
        mapTimer.start();

        auto dimend = dblMapIts.rend();
        for(auto dimit = dblMapIts.rbegin(); dimit != dimend; ++dimit) {
            doubleMap.erase(*dimit);
        }

        int mapEraseTime = mapTimer.elapsed();
        qDebug() << "Map erase time (milliseconds): " + QString::number(mapEraseTime);


        /////////////////////////////
        // insert

        QTime mapInsertTimer;
        mapInsertTimer.start();

        index = 0.0;
        for(auto lit = doubleMap.begin(); lit != doubleMap.end(); ++lit, ++index) {
            if((int)index % processStep == 0) {
                int rand = qMyRand();
                doubleMap.insert(std::make_pair(index + 0.5, rand));
            }
        }

        int mapInsertTime = mapInsertTimer.elapsed();
        qDebug() << "Map insert time (milliseconds): " + QString::number(mapInsertTime);
        qDebug() << "";
    }

    return a.exec();
}
