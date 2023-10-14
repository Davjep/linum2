#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdio.h>
#include <stdlib.h>

static const struct pam_conv conv = {
    misc_conv,
    NULL};

int main(int argc, char *argv[])
{
    pam_handle_t *pamh = NULL;
    int retval;
    const char *user = "nobody";
    if (argc != 2)
    {
        fprintf(stderr, "Usage: check_user [username]\n");
        exit(1);
    }
    user = argv[1];

    retval = pam_start("check_user", user, &conv, &pamh);
    if (retval == PAM_SUCCESS)
    {
        retval = pam_authenticate(pamh, 0); /* is user really user? */
        if (retval == PAM_SUCCESS)
        {
            printf("Auth success!\n");
        }
        else
        {
            printf("Auth failure!\n");
        }
        pam_end(pamh, PAM_SUCCESS);
        return (retval == PAM_SUCCESS) ? 0 : 1;
    }
    fprintf("Error when auth\n");
    return 1;
}