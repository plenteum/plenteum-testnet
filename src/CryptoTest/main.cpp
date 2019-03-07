// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2018-2019, The Plenteum Developers
//
// Please see the included LICENSE file for more information.

#undef NDEBUG

#include <iostream>
#include <chrono>
#include <assert.h>

#include <cxxopts.hpp>
#include <config/CliHeader.h>

#include "CryptoNote.h"
#include "CryptoTypes.h"
#include "Common/StringTools.h"
#include "crypto/crypto.h"

#define PERFORMANCE_ITERATIONS  1000
#define PERFORMANCE_ITERATIONS_LONG_MULTIPLIER 10

using namespace Crypto;
using namespace CryptoNote;

const std::string INPUT_DATA = "0100fb8e8ac805899323371bb790db19218afd8db8e3755d8b90f39b3d5506a9abce4fa912244500000000ee8146d49fa93ee724deb57d12cbc6c6f3b924d946127c7a97418f9348828f0f02";

const std::string CN_FAST_HASH = "b542df5b6e7f5f05275c98e7345884e2ac726aeeb07e03e44e0389eb86cd05f0";

const std::string CN_SLOW_HASH_V0 = "1b606a3f4a07d6489a1bcd07697bd16696b61c8ae982f61a90160f4e52828a7f";
const std::string CN_SLOW_HASH_V1 = "c9fae8425d8688dc236bcdbc42fdb42d376c6ec190501aa84b04a4b4cf1ee122";
const std::string CN_SLOW_HASH_V2 = "871fcd6823f6a879bb3f33951c8e8e891d4043880b02dfa1bb3be498b50e7578";

const std::string CN_LITE_SLOW_HASH_V0 = "28a22bad3f93d1408fca472eb5ad1cbe75f21d053c8ce5b3af105a57713e21dd";
const std::string CN_LITE_SLOW_HASH_V1 = "87c4e570653eb4c2b42b7a0d546559452dfab573b82ec52f152b7ff98e79446f";
const std::string CN_LITE_SLOW_HASH_V2 = "b7e78fab22eb19cb8c9c3afe034fb53390321511bab6ab4915cd538a630c3c62";

const std::string CN_DARK_SLOW_HASH_V0 = "bea42eadd78614f875e55bb972aa5ec54a5edf2dd7068220fda26bf4b1080fb8";
const std::string CN_DARK_SLOW_HASH_V1 = "d18cb32bd5b465e5a7ba4763d60f88b5792f24e513306f1052954294b737e871";
const std::string CN_DARK_SLOW_HASH_V2 = "a18a14d94efea108757a42633a1b4d4dc11838084c3c4347850d39ab5211a91f";

const std::string CN_DARK_LITE_SLOW_HASH_V0 = "faa7884d9c08126eb164814aeba6547b5d6064277a09fb6b414f5dbc9d01eb2b";
const std::string CN_DARK_LITE_SLOW_HASH_V1 = "c75c010780fffd9d5e99838eb093b37c0dd015101c9d298217866daa2993d277";
const std::string CN_DARK_LITE_SLOW_HASH_V2 = "fdceb794c1055977a955f31c576a8be528a0356ee1b0a1f9b7f09e20185cda28";

const std::string CN_TURTLE_SLOW_HASH_V0 = "546c3f1badd7c1232c7a3b88cdb013f7f611b7bd3d1d2463540fccbd12997982";
const std::string CN_TURTLE_SLOW_HASH_V1 = "29e7831780a0ab930e0fe3b965f30e8a44d9b3f9ad2241d67cfbfea3ed62a64e";
const std::string CN_TURTLE_SLOW_HASH_V2 = "fc67dfccb5fc90d7855ae903361eabd76f1e40a22a72ad3ef2d6ad27b5a60ce5";

const std::string CN_TURTLE_LITE_SLOW_HASH_V0 = "5e1891a15d5d85c09baf4a3bbe33675cfa3f77229c8ad66c01779e590528d6d3";
const std::string CN_TURTLE_LITE_SLOW_HASH_V1 = "ae7f864a7a2f2b07dcef253581e60a014972b9655a152341cb989164761c180a";
const std::string CN_TURTLE_LITE_SLOW_HASH_V2 = "b2172ec9466e1aee70ec8572a14c233ee354582bcb93f869d429744de5726a26";


const std::string CN_SOFT_SHELL_V0[] = {
 "6f553876f855587cde08ed6e8d70f078049b68f3fa1c102647cc3dbf2f12a731",
"f365315588ae05fbf10d254e233a7c2e8bbf4ca911fc74a02b3f736ef747df1a",
"a458cf627ed13383c6b6a70de755e0ac5d499a8e41dd81b54c978716fead96ed",
"403bb79bedd2b51ebc6dca7c743aae8fbebcdb26323393e76ba596d7dcf00779",
"5823d513be107c79a6880d514e0743979b2cd6c5046dc3d49f491685e9487837",
"75372eb58c4cbb72a0e1bfda686ad06d7a58964b3549cabca86002b06fae7a23",
"9851999c66761163a3f88f88eff18a45d1787d4fb1ade9985c0da7ee716094fd",
"891c6ad979cfd7e918ee9c941e862a68e1fd262706d17a0bac651b661ad07f68",
"45e96e827a7397ed72d3975d9db6420bf254f66307596a24d0048b1129072be0",
"53a553d8030221a638a127641fbbb3cb1ca28b2ff5579ea74bb94eec31bfe8a5",
"7223383080638f0d68cef76861570bbc34a9fc79d0863c45bec6c76f3b54b0be",
"6beea483d62af81f29a1c5038c0ff9a0a2cccaf63f96d091c38aa0f959279ae9",
"84837c591018d0985ad18ae2b2ffe5dbc8a16460c35e080e3b38327688b13c05",
"649966b1e92ad89bdbd02907d99b33a02336ae6ec58cef1b054b8a3783a1d4db",
"e5ea890915539fc34cc86ef5d47704dd0d1c3dce76328a39f5ee972cf2139db6",
"03c50a53523b1253543d37f04184fcf2e3186a972d93bdca29d08afd43802b81",
"eecb41fe554a75fc2e58822a2aa711c43baf74e45b28fc1543579e757a0d4b13",
"6c2ddfff2e30807f681d1007ebca651e40fa71da6fc2be4ae76246ddbd8634ab",
"a5bb958c0906029e19fea66a7d75b262ce4917bd162f11dad37ee4eca1029bdb",
"1ad682ba54815448742858812c218e4b97b4c29a1d7bd39b9c10e2c6f2316840",
"aa292d59eed1408b32d49882ec54861dab7603c136e1c3b7cba5feb30847d62b",
"0f537b3436aadf29a0f59e1ad8d0d9b48bed3b230910c2a83a5141fd424ff5a4",
"7bb50ec63e818a912c7d18c6a87cabc6941666d8d8a203e20d4b8141d3b88afd",
"321d459949db8fce0f4aab1264501260e4b48ecae4bd8c8cb5acfa3f649d001d",
"07b8564f030d8c4c3036cd0f5a1d28f6f337cad0ee85252e2311c18144beb021",
"808da5d9d061525e0c80928718c84f9c562d308147069b8ab2ba49cbedf05d9b",
"f56637ccae824f75f44b18cd5c820f7c8e78b045f683d2e7b9eede03af2a17d6",
"c806097e833386782924e7016b9698ffb7bdcd95c57918ce313e15c62bb1cc17",
"9c80f20c4fd45c501351507dbf6818f2eafa3bb6751f2674d27d749656e78c7b",
"8247bc17294fde220a02ec2f6c647bf1f85acbdbb7c7c644fdab0446211d042d",
"d860b5977950f6a87bc4855b1dd557c3799c9743756fc3ab376348ac2acb75ba",
"d9d605db731f6ff5ba6a42386f67898d02b1494d042b7a4fedacc97bf5eec7c6",
"5e1891a15d5d85c09baf4a3bbe33675cfa3f77229c8ad66c01779e590528d6d3",
"d9d605db731f6ff5ba6a42386f67898d02b1494d042b7a4fedacc97bf5eec7c6",
"d860b5977950f6a87bc4855b1dd557c3799c9743756fc3ab376348ac2acb75ba",
"8247bc17294fde220a02ec2f6c647bf1f85acbdbb7c7c644fdab0446211d042d",
"9c80f20c4fd45c501351507dbf6818f2eafa3bb6751f2674d27d749656e78c7b",
"c806097e833386782924e7016b9698ffb7bdcd95c57918ce313e15c62bb1cc17",
"f56637ccae824f75f44b18cd5c820f7c8e78b045f683d2e7b9eede03af2a17d6",
"808da5d9d061525e0c80928718c84f9c562d308147069b8ab2ba49cbedf05d9b",
"07b8564f030d8c4c3036cd0f5a1d28f6f337cad0ee85252e2311c18144beb021",
"321d459949db8fce0f4aab1264501260e4b48ecae4bd8c8cb5acfa3f649d001d",
"7bb50ec63e818a912c7d18c6a87cabc6941666d8d8a203e20d4b8141d3b88afd",
"0f537b3436aadf29a0f59e1ad8d0d9b48bed3b230910c2a83a5141fd424ff5a4",
"aa292d59eed1408b32d49882ec54861dab7603c136e1c3b7cba5feb30847d62b",
"1ad682ba54815448742858812c218e4b97b4c29a1d7bd39b9c10e2c6f2316840",
"a5bb958c0906029e19fea66a7d75b262ce4917bd162f11dad37ee4eca1029bdb",
"6c2ddfff2e30807f681d1007ebca651e40fa71da6fc2be4ae76246ddbd8634ab",
"eecb41fe554a75fc2e58822a2aa711c43baf74e45b28fc1543579e757a0d4b13",
"03c50a53523b1253543d37f04184fcf2e3186a972d93bdca29d08afd43802b81",
"e5ea890915539fc34cc86ef5d47704dd0d1c3dce76328a39f5ee972cf2139db6",
"649966b1e92ad89bdbd02907d99b33a02336ae6ec58cef1b054b8a3783a1d4db",
"84837c591018d0985ad18ae2b2ffe5dbc8a16460c35e080e3b38327688b13c05",
"6beea483d62af81f29a1c5038c0ff9a0a2cccaf63f96d091c38aa0f959279ae9",
"7223383080638f0d68cef76861570bbc34a9fc79d0863c45bec6c76f3b54b0be",
"53a553d8030221a638a127641fbbb3cb1ca28b2ff5579ea74bb94eec31bfe8a5",
"45e96e827a7397ed72d3975d9db6420bf254f66307596a24d0048b1129072be0",
"891c6ad979cfd7e918ee9c941e862a68e1fd262706d17a0bac651b661ad07f68",
"9851999c66761163a3f88f88eff18a45d1787d4fb1ade9985c0da7ee716094fd",
"75372eb58c4cbb72a0e1bfda686ad06d7a58964b3549cabca86002b06fae7a23",
"5823d513be107c79a6880d514e0743979b2cd6c5046dc3d49f491685e9487837",
"403bb79bedd2b51ebc6dca7c743aae8fbebcdb26323393e76ba596d7dcf00779",
"a458cf627ed13383c6b6a70de755e0ac5d499a8e41dd81b54c978716fead96ed",
"f365315588ae05fbf10d254e233a7c2e8bbf4ca911fc74a02b3f736ef747df1a",
"6f553876f855587cde08ed6e8d70f078049b68f3fa1c102647cc3dbf2f12a731"
};

const std::string CN_SOFT_SHELL_V1[] = {
  "5dad90c9bdbbcc32a71333cb854f51ba668b2c84ff56e1eeeaf4d76a56c13d12",
  "22e882134c1df145800a188b7291eeaa4075bdbd9cd169a14a4025d17defb94e",
  "71569e43708781402330952e21de281351eb327bcc2f35854ed8f785fb1d5880",
  "7b7d10e65507a8e858924e26e5e03688659a7de72ebf08fb70c4a63cee6b5394",
  "682daee7ca2f6c198d0adaaf304fe227975b68eaf77784411fa5f5df0a2932c7",
  "5573f5a908ba9955fc5069760e6ecd6b55e23af1aa210114755f7a2f1f115729",
  "a21526945df089ef6f600329d1a0c8a31e1bd0c6ebc48798b97d594de156226d",
  "182e709d18385f0bd2e53546480c9a0b5ee08603403f155439a6e55cb555f0c8",
  "29ce5e8fd790eb93a446311ff27580d5dcfda0b56f3b42050ff7c729db1f96d2",
  "47a782036f49ce4f427bd4abf125200e98ff4fe7283a90755076615f83c73465",
  "2c6d58913d70d271cf8f5192e1ccde15130be1bce2e2d934420bd835ce33aa79",
  "6f6e76b6da898d49844b200f4dea8a7c4e57e8e331a1ad715541cf512958a74a",
  "4dbd05e73de0985835f18f0b58340c8a6f0bad0720ebfd8fabbc1b33cd39f5c6",
  "6913312ad0a96fbf3923d7fa55539ab68521602629fb8846bfd007fdc6927f60",
  "ccf84d5427410bcffd18b9c853db2265aef6166b8ab322a2147d9e0ec2d07674",
  "e245e668f19534fcd765282861a505049c38b37d12e6b57149c32dc6bc5e231b",
  "9741c6b7e31cc4c7e990a7f9a6fbe53fa31e5e485b6fb4f852dad93546d3249f",
  "2a96b9bac21eddf11f202c16cbb2494a1bb3ab9def3715ff0d752837de955eec",
  "ca2d1914ad1988dba6b356c54ae6942adfd1cfbbc14ebca9a354166554f4c0a1",
  "dd8cc55ddc68b44f8036f76567acad18b234fdaf6cb719fd95d75daff5e948a1",
  "8af51434d3b5b5d10300591420149988850cc60d3644c5187c930c809933996a",
  "1e2f50b10d2447b0b4beb64197c14886a685144f638ed1fa6647f759dda0cf3d",
  "71a2419e6c46c1d70cc495fa1fb50457be8c35e89e6eca9d05f74b420b87ede0",
  "ffcdacec78b29ca0501a8fa4652bff7f69c34edcdb96e08f9a18efbf51827276",
  "ff61e302e2ca0312f6a2cdfc1be0c5a0b59b535ad902243c7b5ccac7871ef776",
  "827ea0d0ac93f6c43a19e2079d25225b6db90847fcc843aee03c9a0109fdabda",
  "b33bd7f239a0a35373372582d11ba5df1cff4afaf9359a3656cde4b67ed23e05",
  "2f0ca0ab6be2b883a650c2040aa55cf39ca454c22a105075889e67ff45d9e20d",
  "07cff158af47bf8221dc90cfbc174741992b75f691ecca86fda9396f1b13b598",
  "bb69923fac64619a5aaedb421930f3fe5c6a283b22f53c223a7ea79aef98c468",
  "291532e762e6e4ca6987813d2d11b88ca2b1cddec68d539f8e4c8339e7f73996",
  "a9f064ea5634fdb6ec42057adf1244eac4dd65ee4d22fd6bea08bb45bd406bbd",
  "ae7f864a7a2f2b07dcef253581e60a014972b9655a152341cb989164761c180a",
  "a9f064ea5634fdb6ec42057adf1244eac4dd65ee4d22fd6bea08bb45bd406bbd",
  "291532e762e6e4ca6987813d2d11b88ca2b1cddec68d539f8e4c8339e7f73996",
  "bb69923fac64619a5aaedb421930f3fe5c6a283b22f53c223a7ea79aef98c468",
  "07cff158af47bf8221dc90cfbc174741992b75f691ecca86fda9396f1b13b598",
  "2f0ca0ab6be2b883a650c2040aa55cf39ca454c22a105075889e67ff45d9e20d",
  "b33bd7f239a0a35373372582d11ba5df1cff4afaf9359a3656cde4b67ed23e05",
  "827ea0d0ac93f6c43a19e2079d25225b6db90847fcc843aee03c9a0109fdabda",
  "ff61e302e2ca0312f6a2cdfc1be0c5a0b59b535ad902243c7b5ccac7871ef776",
  "ffcdacec78b29ca0501a8fa4652bff7f69c34edcdb96e08f9a18efbf51827276",
  "71a2419e6c46c1d70cc495fa1fb50457be8c35e89e6eca9d05f74b420b87ede0",
  "1e2f50b10d2447b0b4beb64197c14886a685144f638ed1fa6647f759dda0cf3d",
  "8af51434d3b5b5d10300591420149988850cc60d3644c5187c930c809933996a",
  "dd8cc55ddc68b44f8036f76567acad18b234fdaf6cb719fd95d75daff5e948a1",
  "ca2d1914ad1988dba6b356c54ae6942adfd1cfbbc14ebca9a354166554f4c0a1",
  "2a96b9bac21eddf11f202c16cbb2494a1bb3ab9def3715ff0d752837de955eec",
  "9741c6b7e31cc4c7e990a7f9a6fbe53fa31e5e485b6fb4f852dad93546d3249f",
  "e245e668f19534fcd765282861a505049c38b37d12e6b57149c32dc6bc5e231b",
  "ccf84d5427410bcffd18b9c853db2265aef6166b8ab322a2147d9e0ec2d07674",
  "6913312ad0a96fbf3923d7fa55539ab68521602629fb8846bfd007fdc6927f60",
  "4dbd05e73de0985835f18f0b58340c8a6f0bad0720ebfd8fabbc1b33cd39f5c6",
  "6f6e76b6da898d49844b200f4dea8a7c4e57e8e331a1ad715541cf512958a74a",
  "2c6d58913d70d271cf8f5192e1ccde15130be1bce2e2d934420bd835ce33aa79",
  "47a782036f49ce4f427bd4abf125200e98ff4fe7283a90755076615f83c73465",
  "29ce5e8fd790eb93a446311ff27580d5dcfda0b56f3b42050ff7c729db1f96d2",
  "182e709d18385f0bd2e53546480c9a0b5ee08603403f155439a6e55cb555f0c8",
  "a21526945df089ef6f600329d1a0c8a31e1bd0c6ebc48798b97d594de156226d",
  "5573f5a908ba9955fc5069760e6ecd6b55e23af1aa210114755f7a2f1f115729",
  "682daee7ca2f6c198d0adaaf304fe227975b68eaf77784411fa5f5df0a2932c7",
  "7b7d10e65507a8e858924e26e5e03688659a7de72ebf08fb70c4a63cee6b5394",
  "71569e43708781402330952e21de281351eb327bcc2f35854ed8f785fb1d5880",
  "22e882134c1df145800a188b7291eeaa4075bdbd9cd169a14a4025d17defb94e",
  "5dad90c9bdbbcc32a71333cb854f51ba668b2c84ff56e1eeeaf4d76a56c13d12"
};

const std::string CN_SOFT_SHELL_V2[] = {
  "61b020ebb2385112f5474c74b8c202df157c036145363174210d33aba60bd60d",
  "6acb6403c447c2130f818108339a51b43e98b2acaf9209ad4bfcebdece51dfb5",
  "7b8134af1ba4172db892fb37ec72e5f7b802117b38fe879fc36a0cc887205412",
  "393dbb2079507b7617e5b09ec4a074e9c09dedb906ff3e219e977ead765421e1",
  "714565d2491d45b89b3d2f53ce77359ee082df576a3e4c1250cc4157bb32d85c",
  "b9757366c17d787f3be60854cd2efce3a8252a75a998508b26f162a1f1b2a783",
  "c0ed9b99350b4028ab9020ea6b500740f9150bcbcb3091b52b62340b9c40ddee",
  "5c5da3066aa63e5df5408fb5ad43d5bafffe435c34cfe9bf07f198421f79262f",
  "9d781edbd1a3249c82faf9b4fcf900904e72c28849df4b901644b3fc3f20ebea",
  "7fe5c3b2d767a8ffd066f13bcc11cb0be78d54413f6e551042a58cf1e506d0e3",
  "95f4947071b82db38630603c606ed829b83d33050a2a9cdd4b2823b4933effda",
  "87b0d351e5b5ae345885d0220ea92d8b21617cd4eee2dc5b4a1e5cc9e5fe0dfa",
  "1c6a114499ac6da25fd5aa952471b1f50ee600b9e3a2439bcdd1e2f8dec8760e",
  "40735b8ded9e8c0425251bb8f62bf22babc22a71044168fc89ffeb0b9ae43917",
  "c1f1f8b99f3a16d68eff0bd5af94a2aab47beeea5a1ce114ffd56bce33217cd0",
  "604a19a47cf0a6915604b02f4e0e7aa81fbede962b9709dcbcdbc7e55ba09fad",
  "0a770bba6022bd92c8cb044c565f4680a12491c5f0a24f67240026a2b593abff",
  "b855f3f9e05a3d84971c8ee2af758a73ed2aa8770f829c7cb2e8c497ef85682f",
  "1b6cbc98cbc482f37d9fedea3c8ab07581463e4872b18fa776f9ffe610adab75",
  "ae62482cbed77e506c5cec20e50321e509bdf551aadcaf6cf508179807d33f12",
  "2e9b8c214bc1f70db80a05339f9aaf03d4ddb903ce663fefbf4bfb74637960ea",
  "482bae55f55854da2a7191792baf1692d39e7146556db421aeb1d723dd836b58",
  "a7f7f467106b0f3b8802df6ca996df9d2891645dcc866be0294af19b1b4efb92",
  "2d84d3c72d387b5b00493bbfbc1e0a3459a68a37b4ae5774e3d7b8d48bc3baf1",
  "f3ec95974e5f89a43e131b753aaca0cf4d651c01f661c9cb756331272a377a8d",
  "5fb257d16ec56f9433c9049ea2ddad38b8e2b5e56db6fcc30eaad4ee45683699",
  "15b714b6dbbcd3443559b96a3d285a4c9f68ad2ce575eed7c326a1637df1302d",
  "00a189b0e55bf02ea19c4a675ad82d831039735dc4d6766f13daa222d7cfde60",
  "fab3945ce9a76d096273da994fcaae604be2ca76673126ecca9c304591ef67e7",
  "8158c57e2b563c0281ad2ab4e6efdea42065a968a52c625d163ad269f19eea26",
  "faad60e19f001d1012ad1aacc83bd3f93bfe51d02b90eb9b232ceda28d542470",
  "d1f23b0373adbe06f4db880b09327372ebca82a2198792ab229ddf7aefdec1a5",
  "b2172ec9466e1aee70ec8572a14c233ee354582bcb93f869d429744de5726a26",
  "d1f23b0373adbe06f4db880b09327372ebca82a2198792ab229ddf7aefdec1a5",
  "faad60e19f001d1012ad1aacc83bd3f93bfe51d02b90eb9b232ceda28d542470",
  "8158c57e2b563c0281ad2ab4e6efdea42065a968a52c625d163ad269f19eea26",
  "fab3945ce9a76d096273da994fcaae604be2ca76673126ecca9c304591ef67e7",
  "00a189b0e55bf02ea19c4a675ad82d831039735dc4d6766f13daa222d7cfde60",
  "15b714b6dbbcd3443559b96a3d285a4c9f68ad2ce575eed7c326a1637df1302d",
  "5fb257d16ec56f9433c9049ea2ddad38b8e2b5e56db6fcc30eaad4ee45683699",
  "f3ec95974e5f89a43e131b753aaca0cf4d651c01f661c9cb756331272a377a8d",
  "2d84d3c72d387b5b00493bbfbc1e0a3459a68a37b4ae5774e3d7b8d48bc3baf1",
  "a7f7f467106b0f3b8802df6ca996df9d2891645dcc866be0294af19b1b4efb92",
  "482bae55f55854da2a7191792baf1692d39e7146556db421aeb1d723dd836b58",
  "2e9b8c214bc1f70db80a05339f9aaf03d4ddb903ce663fefbf4bfb74637960ea",
  "ae62482cbed77e506c5cec20e50321e509bdf551aadcaf6cf508179807d33f12",
  "1b6cbc98cbc482f37d9fedea3c8ab07581463e4872b18fa776f9ffe610adab75",
  "b855f3f9e05a3d84971c8ee2af758a73ed2aa8770f829c7cb2e8c497ef85682f",
  "0a770bba6022bd92c8cb044c565f4680a12491c5f0a24f67240026a2b593abff",
  "604a19a47cf0a6915604b02f4e0e7aa81fbede962b9709dcbcdbc7e55ba09fad",
  "c1f1f8b99f3a16d68eff0bd5af94a2aab47beeea5a1ce114ffd56bce33217cd0",
  "40735b8ded9e8c0425251bb8f62bf22babc22a71044168fc89ffeb0b9ae43917",
  "1c6a114499ac6da25fd5aa952471b1f50ee600b9e3a2439bcdd1e2f8dec8760e",
  "87b0d351e5b5ae345885d0220ea92d8b21617cd4eee2dc5b4a1e5cc9e5fe0dfa",
  "95f4947071b82db38630603c606ed829b83d33050a2a9cdd4b2823b4933effda",
  "7fe5c3b2d767a8ffd066f13bcc11cb0be78d54413f6e551042a58cf1e506d0e3",
  "9d781edbd1a3249c82faf9b4fcf900904e72c28849df4b901644b3fc3f20ebea",
  "5c5da3066aa63e5df5408fb5ad43d5bafffe435c34cfe9bf07f198421f79262f",
  "c0ed9b99350b4028ab9020ea6b500740f9150bcbcb3091b52b62340b9c40ddee",
  "b9757366c17d787f3be60854cd2efce3a8252a75a998508b26f162a1f1b2a783",
  "714565d2491d45b89b3d2f53ce77359ee082df576a3e4c1250cc4157bb32d85c",
  "393dbb2079507b7617e5b09ec4a074e9c09dedb906ff3e219e977ead765421e1",
  "7b8134af1ba4172db892fb37ec72e5f7b802117b38fe879fc36a0cc887205412",
  "6acb6403c447c2130f818108339a51b43e98b2acaf9209ad4bfcebdece51dfb5",
  "61b020ebb2385112f5474c74b8c202df157c036145363174210d33aba60bd60d"
};

static inline bool CompareHashes(const Hash leftHash, const std::string right)
{
  Hash rightHash = Hash();
  if (!Common::podFromHex(right, rightHash)) {
    return false;
  }

  return (leftHash == rightHash);
}

/* Check if we're testing a v1 or v2 hash function */
/* Hacky as fuck lmao */
bool need43BytesOfData(std::string hashFunctionName)
{
    return (hashFunctionName.find("v1") != std::string::npos 
        || hashFunctionName.find("v2") != std::string::npos);
}

/* Bit of hackery so we can get the variable name of the passed in function.
   This way we can print the test we are currently performing. */
#define TEST_HASH_FUNCTION(hashFunction, expectedOutput) \
   testHashFunction(hashFunction, expectedOutput, #hashFunction, -1)

#define TEST_HASH_FUNCTION_WITH_HEIGHT(hashFunction, expectedOutput, height) \
    testHashFunction(hashFunction, expectedOutput, #hashFunction, height, height)

template<typename T, typename ...Args>
void testHashFunction(
    T hashFunction,
    std::string expectedOutput,
    std::string hashFunctionName,
    int64_t height,
    Args && ... args)
{
    const BinaryArray& rawData = Common::fromHex(INPUT_DATA);

    if (need43BytesOfData(hashFunctionName) && rawData.size() < 43)
    {
        return;
    }

    Hash hash = Hash();

    /* Perform the hash, with a height if given */
    hashFunction(rawData.data(), rawData.size(), hash, std::forward<Args>(args)...);

    if (height == -1)
    {
		std::cout << hashFunctionName << ": " << hash << std::endl;
    }
    else
    {
		std::cout << hashFunctionName << " (" << height << "): " << hash << std::endl;
    }

    /* Verify the hash is as expected */
    assert(CompareHashes(hash, expectedOutput));
}

/* Bit of hackery so we can get the variable name of the passed in function.
   This way we can print the test we are currently performing. */
#define BENCHMARK(hashFunction, iterations) \
   benchmark(hashFunction, #hashFunction, iterations)

template<typename T>
void benchmark(T hashFunction, std::string hashFunctionName, uint64_t iterations)
{
    const BinaryArray& rawData = Common::fromHex(INPUT_DATA);

    if (need43BytesOfData(hashFunctionName) && rawData.size() < 43)
    {
        return;
    }

    Hash hash = Hash();

    auto startTimer = std::chrono::high_resolution_clock::now();

    for (uint64_t i = 0; i < iterations; i++)
    {
        hashFunction(rawData.data(), rawData.size(), hash);
    }

    auto elapsedTime = std::chrono::high_resolution_clock::now() - startTimer;

    std::cout << hashFunctionName << ": "
              << (iterations / std::chrono::duration_cast<std::chrono::seconds>(elapsedTime).count())
              << " H/s\n";
}

void benchmarkUnderivePublicKey()
{
    Crypto::KeyDerivation derivation;

    Crypto::PublicKey txPublicKey;
    Common::podFromHex("f235acd76ee38ec4f7d95123436200f9ed74f9eb291b1454fbc30742481be1ab", txPublicKey);

    Crypto::SecretKey privateViewKey;
    Common::podFromHex("89df8c4d34af41a51cfae0267e8254cadd2298f9256439fa1cfa7e25ee606606", privateViewKey);

    Crypto::generate_key_derivation(txPublicKey, privateViewKey, derivation);

    const uint64_t loopIterations = 600000;

    auto startTimer = std::chrono::high_resolution_clock::now();

    Crypto::PublicKey spendKey;

    Crypto::PublicKey outputKey;
    Common::podFromHex("4a078e76cd41a3d3b534b83dc6f2ea2de500b653ca82273b7bfad8045d85a400", outputKey);

    for (uint64_t i = 0; i < loopIterations; i++)
    {
        /* Use i as output index to prevent optimization */
        Crypto::underive_public_key(derivation, i, outputKey, spendKey);
    }

    auto elapsedTime = std::chrono::high_resolution_clock::now() - startTimer;

    /* Need to use microseconds here then divide by 1000 - otherwise we'll just get '0' */
    const auto timePerDerivation = std::chrono::duration_cast<std::chrono::microseconds>(elapsedTime).count() / loopIterations;

    std::cout << "Time to perform underivePublicKey: " << timePerDerivation / 1000.0 << " ms" << std::endl;
}

void benchmarkGenerateKeyDerivation()
{
    Crypto::KeyDerivation derivation;

    Crypto::PublicKey txPublicKey;
    Common::podFromHex("f235acd76ee38ec4f7d95123436200f9ed74f9eb291b1454fbc30742481be1ab", txPublicKey);

    Crypto::SecretKey privateViewKey;
    Common::podFromHex("89df8c4d34af41a51cfae0267e8254cadd2298f9256439fa1cfa7e25ee606606", privateViewKey);

    const uint64_t loopIterations = 60000;

    auto startTimer = std::chrono::high_resolution_clock::now();

    for (uint64_t i = 0; i < loopIterations; i++)
    {
        Crypto::generate_key_derivation(txPublicKey, privateViewKey, derivation);
    }

    auto elapsedTime = std::chrono::high_resolution_clock::now() - startTimer;

    const auto timePerDerivation = std::chrono::duration_cast<std::chrono::microseconds>(elapsedTime).count() / loopIterations;

    std::cout << "Time to perform generateKeyDerivation: " << timePerDerivation / 1000.0 << " ms" << std::endl;
}

int main(int argc, char** argv)
{
    bool o_help, o_version, o_benchmark;
    int o_iterations;

    cxxopts::Options options(argv[0], getProjectCLIHeader());

    options.add_options("Core")
        ("h,help", "Display this help message", cxxopts::value<bool>(o_help)->implicit_value("true"))
        ("v,version", "Output software version information", cxxopts::value<bool>(o_version)->default_value("false")->implicit_value("true"));

    options.add_options("Performance Testing")
        ("b,benchmark", "Run quick performance benchmark", cxxopts::value<bool>(o_benchmark)->default_value("false")->implicit_value("true"))
        ("i,iterations", "The number of iterations for the benchmark test. Minimum of 1,000 iterations required.",
            cxxopts::value<int>(o_iterations)->default_value(std::to_string(PERFORMANCE_ITERATIONS)), "#");

    try
    {
        auto result = options.parse(argc, argv);
    }
    catch (const cxxopts::OptionException& e)
    {
        std::cout << "Error: Unable to parse command line argument options: " << e.what() << std::endl << std::endl;
        std::cout << options.help({}) << std::endl;
        exit(1);
    }

    if (o_help) // Do we want to display the help message?
    {
        std::cout << options.help({}) << std::endl;
        exit(0);
    }
    else if (o_version) // Do we want to display the software version?
    {
        std::cout << getProjectCLIHeader() << std::endl;
        exit(0);
    }

    if (o_iterations < 1000 && o_benchmark)
    {
        std::cout << std::endl << "Error: The number of --iterations should be at least 1,000 for reasonable accuracy" << std::endl;
        exit(1);
    }

    int o_iterations_long = o_iterations * PERFORMANCE_ITERATIONS_LONG_MULTIPLIER;

    try
    {
        std::cout << getProjectCLIHeader() << std::endl;

        std::cout << "Input: " << INPUT_DATA << std::endl << std::endl;

        TEST_HASH_FUNCTION(cn_slow_hash_v0, CN_SLOW_HASH_V0);
        TEST_HASH_FUNCTION(cn_slow_hash_v1, CN_SLOW_HASH_V1);
        TEST_HASH_FUNCTION(cn_slow_hash_v2, CN_SLOW_HASH_V2);
        
        std::cout << std::endl;

        TEST_HASH_FUNCTION(cn_lite_slow_hash_v0, CN_LITE_SLOW_HASH_V0);
        TEST_HASH_FUNCTION(cn_lite_slow_hash_v1, CN_LITE_SLOW_HASH_V1);
        TEST_HASH_FUNCTION(cn_lite_slow_hash_v2, CN_LITE_SLOW_HASH_V2);

        std::cout << std::endl;

        TEST_HASH_FUNCTION(cn_dark_slow_hash_v0, CN_DARK_SLOW_HASH_V0);
        TEST_HASH_FUNCTION(cn_dark_slow_hash_v1, CN_DARK_SLOW_HASH_V1);
        TEST_HASH_FUNCTION(cn_dark_slow_hash_v2, CN_DARK_SLOW_HASH_V2);

        std::cout << std::endl;

        TEST_HASH_FUNCTION(cn_dark_lite_slow_hash_v0, CN_DARK_LITE_SLOW_HASH_V0);
        TEST_HASH_FUNCTION(cn_dark_lite_slow_hash_v1, CN_DARK_LITE_SLOW_HASH_V1);
        TEST_HASH_FUNCTION(cn_dark_lite_slow_hash_v2, CN_DARK_LITE_SLOW_HASH_V2);
        
        std::cout << std::endl;

        TEST_HASH_FUNCTION(cn_turtle_slow_hash_v0, CN_TURTLE_SLOW_HASH_V0);
        TEST_HASH_FUNCTION(cn_turtle_slow_hash_v1, CN_TURTLE_SLOW_HASH_V1);
        TEST_HASH_FUNCTION(cn_turtle_slow_hash_v2, CN_TURTLE_SLOW_HASH_V2);

        std::cout << std::endl;

        TEST_HASH_FUNCTION(cn_turtle_lite_slow_hash_v0, CN_TURTLE_LITE_SLOW_HASH_V0);
        TEST_HASH_FUNCTION(cn_turtle_lite_slow_hash_v1, CN_TURTLE_LITE_SLOW_HASH_V1);
        TEST_HASH_FUNCTION(cn_turtle_lite_slow_hash_v2, CN_TURTLE_LITE_SLOW_HASH_V2);

        std::cout << std::endl;

		for (uint64_t height = 12256; height <= 12320; height++)
        {
            TEST_HASH_FUNCTION_WITH_HEIGHT(cn_soft_shell_slow_hash_v0, CN_SOFT_SHELL_V0[height - 12256], height);
        }

        std::cout << std::endl;

		for (uint64_t height = 12256; height <= 12320; height++)
        {
            TEST_HASH_FUNCTION_WITH_HEIGHT(cn_soft_shell_slow_hash_v1, CN_SOFT_SHELL_V1[height - 12256], height);
        }

        std::cout << std::endl;

		for (uint64_t height = 12256; height <= 12320; height++)
        {
            TEST_HASH_FUNCTION_WITH_HEIGHT(cn_soft_shell_slow_hash_v2, CN_SOFT_SHELL_V2[height - 12256], height);
        }

        if (o_benchmark)
        {
            std::cout <<  "\nPerformance Tests: Please wait, this may take a while depending on your system...\n\n";

            benchmarkUnderivePublicKey();
            benchmarkGenerateKeyDerivation();

            BENCHMARK(cn_slow_hash_v0, o_iterations);
            BENCHMARK(cn_slow_hash_v1, o_iterations);
            BENCHMARK(cn_slow_hash_v2, o_iterations);

            BENCHMARK(cn_lite_slow_hash_v0, o_iterations);
            BENCHMARK(cn_lite_slow_hash_v1, o_iterations);
            BENCHMARK(cn_lite_slow_hash_v2, o_iterations);

            BENCHMARK(cn_dark_slow_hash_v0, o_iterations);
            BENCHMARK(cn_dark_slow_hash_v1, o_iterations);
            BENCHMARK(cn_dark_slow_hash_v2, o_iterations);

            BENCHMARK(cn_dark_lite_slow_hash_v0, o_iterations);
            BENCHMARK(cn_dark_lite_slow_hash_v1, o_iterations);
            BENCHMARK(cn_dark_lite_slow_hash_v2, o_iterations);

            BENCHMARK(cn_turtle_slow_hash_v0, o_iterations_long);
            BENCHMARK(cn_turtle_slow_hash_v1, o_iterations_long);
            BENCHMARK(cn_turtle_slow_hash_v2, o_iterations_long);

            BENCHMARK(cn_turtle_lite_slow_hash_v0, o_iterations_long);
            BENCHMARK(cn_turtle_lite_slow_hash_v1, o_iterations_long);
            BENCHMARK(cn_turtle_lite_slow_hash_v2, o_iterations_long);
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Something went terribly wrong...\n" << e.what() << "\n\n";
    }
}
