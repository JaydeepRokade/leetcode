class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        //sxkskk jsnnslkk ks/kdlklldca.dv ndkjnnsvkj kjcsj,ncn//lnvljnclj nljcnwlnc lndljn'l ndvls'llj ljcsslcc jncvljnflj ldjvnen jdvljdn ldvl 'ln 'dnv'dl lnc lfjbljdal l n'lvvldldl vdv''dv  vav
        vector<vector<int>> mergedMeetings;
        for (const auto& meeting : meetings) {
            if (mergedMeetings.empty() || meeting[0] > mergedMeetings.back()[1]) {
                mergedMeetings.push_back(meeting);
            } else {
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meeting[1]);
            }
        }

        int meetingDaysCount = 0;
        for (const auto& m : mergedMeetings) {
            meetingDaysCount += (m[1] - m[0] + 1);
        }

        return days - meetingDaysCount;
    }
};
