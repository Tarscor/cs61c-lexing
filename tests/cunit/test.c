#include <stddef.h>
#include "../../string-helpers.h"
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>
#include "test.h"

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void) {
  return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void) {
  return 0;
}

/* The test initialization function.
 * Opens the temporary file used by the test.
 */
void init_test1(void) {
  return;
}

/* The test cleanup function.
 * Closes the temporary file used by the test in particular.
 */
void clean_test1(void) {
  return;
}

/* Simple test of is_digit().
 */
void testISDIGIT_Integers(void) {
  CU_ASSERT_FALSE(is_digit(0));
  CU_ASSERT_FALSE(is_digit(9));
  CU_ASSERT_FALSE(is_digit(-1));
}

void testISDIGIT_Digits(void) {
  CU_ASSERT_TRUE(is_digit('1'));
  CU_ASSERT_TRUE(is_digit('0'));
  CU_ASSERT_TRUE(is_digit('9'));
}

void testISDIGIT_EscChars(void) {
  CU_ASSERT_FALSE(is_digit('\0'));
  CU_ASSERT_FALSE(is_digit('\"'));
  CU_ASSERT_FALSE(is_digit('\n'));
}

/* Simple test of lower_strcopy().
 */
void testLOWERSTRCPY_Lower(void) {
  char* src = "hello";
  char empty[6];
  char* dest = empty;
  lower_strcpy(dest, src);
  CU_ASSERT(strcmp(dest, "hello") == 0);
}
void testLOWERSTRCPY_Upper(void) {
  char* src = "HELLO";
  char empty[6];
  char* dest = empty;
  lower_strcpy(dest, src);
  CU_ASSERT(strcmp(dest, "hello") == 0);
}
void testLOWERSTRCPY_Both(void) {;
  char* src = "HeLlO";
  char empty[6];
  char* dest = empty;
  lower_strcpy(dest, src);
  CU_ASSERT(strcmp(dest,  "hello") == 0);
}

/* Simple test of replace_escape_in_character().
 */
void testREPLACEESCAPECHAR_NoEscape(void) {
  char* p1 = "n";
  char* p2 = "0";
  
  CU_ASSERT(replace_escape_in_character(p1) == -1);
  CU_ASSERT(replace_escape_in_character(p2) == -1);
}
void testREPLACEESCAPECHAR_Escaped(void) {
  char* p3 = "\\n";
  char* p4 = "\\t";
  char* p5 = "\\0";
  char* p6 = "\\\\";
  char* p7 = "\\\'";
  
  CU_ASSERT(replace_escape_in_character(p3) == '\n');
  CU_ASSERT(replace_escape_in_character(p4) == '\t');
  CU_ASSERT(replace_escape_in_character(p5) == '\0');
  CU_ASSERT(replace_escape_in_character(p6) == '\\');
  CU_ASSERT(replace_escape_in_character(p7) == '\'');
}
void testREPLACEESCAPECHAR_NotEscapedChar(void) {
  char* p8 = "\\a";
  char* p9 = "\\p";
  CU_ASSERT(replace_escape_in_character(p8) == -1);
  CU_ASSERT(replace_escape_in_character(p9) == -1);
}

/* Simple test of replace_escape_in_string().
 */
void testREPLACEESCAPESTR_NoEscape(void) {
  char* p1 = "n";
  char* p2 = "0";

  CU_ASSERT(replace_escape_in_string(p1) == -1);
  CU_ASSERT(replace_escape_in_string(p2) == -1);
}
void testREPLACEESCAPESTR_Escaped(void) {
  char* p3 = "\\n";
  char* p4 = "\\t";
  char* p5 = "\\0";
  char* p6 = "\\\\";
  char* p7 = "\\\"";

  CU_ASSERT(replace_escape_in_string(p3) == '\n');
  CU_ASSERT(replace_escape_in_string(p4) == '\t');
  CU_ASSERT(replace_escape_in_string(p5) == '\0');
  CU_ASSERT(replace_escape_in_string(p6) == '\\');
  CU_ASSERT(replace_escape_in_string(p7) == '"');
}
void testREPLACEESCAPESTR_NotEscapedChar(void) {
  char* p8 = "\\a";
  char* p9 = "\\p";
  CU_ASSERT(replace_escape_in_string(p8) == -1);
  CU_ASSERT(replace_escape_in_string(p9) == -1);
}

/* Simple test of is_alpha().
 */
void testISALPHA_CapLetters(void) {
  CU_ASSERT_TRUE(is_alpha('A'));
  CU_ASSERT_TRUE(is_alpha('Z'));
  CU_ASSERT_TRUE(is_alpha('P'));
}

void testISALPHA_LowLetters(void) {
  CU_ASSERT_TRUE(is_alpha('a'));
  CU_ASSERT_TRUE(is_alpha('z'));
  CU_ASSERT_TRUE(is_alpha('p'));
}

void testISALPHA_NotLetters(void) {
  CU_ASSERT_FALSE(is_alpha('0'));
  CU_ASSERT_FALSE(is_alpha(' '));
}

void testISALPHA_EscChars(void) {
  CU_ASSERT_FALSE(is_alpha('\0'));
  CU_ASSERT_FALSE(is_alpha('\"'));
  CU_ASSERT_FALSE(is_alpha('\n'));
}

/* Simple test of is_space().
 */
void testISSPACE_Space(void) {
  CU_ASSERT_TRUE(is_space(' '));
}

void testISSPACE_Digit(void) {
  CU_ASSERT_FALSE(is_space('1'));
}

void testISSPACE_Letter(void) {
  CU_ASSERT_FALSE(is_space('A'));
}

void testISSPACE_EscChars(void) {
  CU_ASSERT_FALSE(is_digit('\0'));
  CU_ASSERT_FALSE(is_digit('\"'));
  CU_ASSERT_FALSE(is_digit('\n'));
}

/* Simple test of is_identifier_component().
 */
void testISIDCOMP_Letters(void) {
  CU_ASSERT_TRUE(is_identifier_component('A'));
  CU_ASSERT_TRUE(is_identifier_component('Z'));
  CU_ASSERT_TRUE(is_identifier_component('P'));
  CU_ASSERT_TRUE(is_identifier_component('a'));
  CU_ASSERT_TRUE(is_identifier_component('z'));
  CU_ASSERT_TRUE(is_identifier_component('p'));
}

void testISIDCOMP_Digits(void) {
  CU_ASSERT_TRUE(is_identifier_component('1'));
  CU_ASSERT_TRUE(is_identifier_component('0'));
  CU_ASSERT_TRUE(is_identifier_component('9'));
}

void testISIDCOMP_Underscore(void) {
  CU_ASSERT_TRUE(is_identifier_component('_'));
}

void testISIDCOMP_EscChars(void) {
  CU_ASSERT_FALSE(is_identifier_component('\0'));
  CU_ASSERT_FALSE(is_identifier_component('\"'));
  CU_ASSERT_FALSE(is_identifier_component('\n'));
}

/* Simple test of is_valid_identifier().
 */
void testISVALIDID_Letters(void) {
  CU_ASSERT_TRUE(is_valid_identifier("A"));
  CU_ASSERT_TRUE(is_valid_identifier("Z"));
  CU_ASSERT_TRUE(is_valid_identifier("P"));
  CU_ASSERT_TRUE(is_valid_identifier("aZ"));
  CU_ASSERT_TRUE(is_valid_identifier("Zp"));
  CU_ASSERT_TRUE(is_valid_identifier("az"));
}

void testISVALIDID_Digits(void) {
  CU_ASSERT_TRUE(is_valid_identifier("1"));
  CU_ASSERT_TRUE(is_valid_identifier("0"));
  CU_ASSERT_TRUE(is_valid_identifier("9"));
  CU_ASSERT_TRUE(is_valid_identifier("19"));
  CU_ASSERT_TRUE(is_valid_identifier("01"));
  CU_ASSERT_TRUE(is_valid_identifier("90"));
}

void testISVALIDID_Underscore(void) {
  CU_ASSERT_TRUE(is_valid_identifier("_"));
  CU_ASSERT_TRUE(is_valid_identifier("___"));
}

void testISVALIDID_All(void) {
  CU_ASSERT_TRUE(is_valid_identifier("A0"));
  CU_ASSERT_TRUE(is_valid_identifier("Z_"));
  CU_ASSERT_TRUE(is_valid_identifier("P_a"));
  CU_ASSERT_TRUE(is_valid_identifier("9_Z"));
  CU_ASSERT_TRUE(is_valid_identifier("_l4"));
  CU_ASSERT_TRUE(is_valid_identifier("7Q_"));
}


/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main() {
  CU_TestInfo isdigit_tests[] = {{"Test actual digits", testISDIGIT_Digits},
                                 {"Test esc chars", testISDIGIT_EscChars},
                                 {"Test numbers", testISDIGIT_Integers},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite1[] = {{"is_digit testing", init_suite1, clean_suite1,
                           isdigit_tests},
                           CU_SUITE_INFO_NULL};

  CU_TestInfo lowerstrcpy_tests[] = {{"Test lowercase letters", testLOWERSTRCPY_Lower},
                                 {"Test uppercase letters", testLOWERSTRCPY_Upper},
                                 {"Test both lowercase and uppercase letters", testLOWERSTRCPY_Both},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite2[] = {{"lower_strcpy testing", init_suite1, clean_suite1,
                           lowerstrcpy_tests},
                           CU_SUITE_INFO_NULL};

  CU_TestInfo replaceescapechar_tests[] = {{"Test missing escape", testREPLACEESCAPECHAR_NoEscape},
                                 {"Test escaped characters", testREPLACEESCAPECHAR_Escaped},
                                 {"Test illegal escaped characters", testREPLACEESCAPECHAR_NotEscapedChar},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite3[] = {{"replace_escape_in_character testing", init_suite1, clean_suite1,
                           replaceescapechar_tests},
                           CU_SUITE_INFO_NULL};

 CU_TestInfo replaceescapestr_tests[] = {{"Test missing escape", testREPLACEESCAPESTR_NoEscape},
                                 {"Test escaped characters", testREPLACEESCAPESTR_Escaped},
                                 {"Test illegal escaped characters", testREPLACEESCAPESTR_NotEscapedChar},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite4[] = {{"replace_escape_in_string testing", init_suite1, clean_suite1,
                           replaceescapestr_tests},
                           CU_SUITE_INFO_NULL};

CU_TestInfo isalpha_tests[] = {{"Test actual capitalized letters", testISALPHA_CapLetters},
				 {"Test actual lowercased letters", testISALPHA_LowLetters},
                                 {"Test esc chars", testISALPHA_EscChars},
                                 {"Test non-letters", testISALPHA_NotLetters},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite5[] = {{"is_alpha testing", init_suite1, clean_suite1,
                           isalpha_tests},
                           CU_SUITE_INFO_NULL};

CU_TestInfo isspace_tests[] = {{"Test actual space", testISSPACE_Space},
                                 {"Test a digit", testISSPACE_Digit},
                                 {"Test a letter", testISSPACE_Letter},
                                 {"Test esp chars", testISSPACE_EscChars},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite6[] = {{"is_space testing", init_suite1, clean_suite1,
                           isspace_tests},
                           CU_SUITE_INFO_NULL};

CU_TestInfo isidcomp_tests[] = {{"Test letters", testISIDCOMP_Letters},
                                 {"Test digits", testISIDCOMP_Digits},
                                 {"Test underscore", testISIDCOMP_Underscore},
                                 {"Test esp chars", testISIDCOMP_EscChars},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite7[] = {{"is_identifier_component testing", init_suite1, clean_suite1,
                           isidcomp_tests},
                           CU_SUITE_INFO_NULL};

CU_TestInfo isvalidid_tests[] = {{"Test letters", testISVALIDID_Letters},
                                 {"Test digits", testISVALIDID_Digits},
                                 {"Test underscore", testISVALIDID_Underscore},
                                 {"Test string with all identifiers", testISVALIDID_All},
                                 CU_TEST_INFO_NULL};

  CU_SuiteInfo suite8[] = {{"is_valid_identifier testing", init_suite1, clean_suite1,
                           isvalidid_tests},
                           CU_SUITE_INFO_NULL};

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  if (CU_register_suites(suite1)
|| CU_register_suites(suite2)
|| CU_register_suites(suite3)
|| CU_register_suites(suite4)
|| CU_register_suites(suite5)
|| CU_register_suites(suite6) 
|| CU_register_suites(suite7) 
|| CU_register_suites(suite8)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
